#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gqueue.h"
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#define MAX_MARKS 4 // mark를 사용할 수 있는 최대 횟수

typedef enum {
    closed, marked, open
}
cell_state;

typedef struct { //mined, numbered(팔방으로 주변에 지뢰가 몇개인지)
    int mined;
    int num;
    cell_state state;
}
cell_t;


int M, N, K; //board 구성: M rows, N col, K cells where mine placed
cell_t board[16][16] = { { {0, 0, 0} } }; //지뢰 아니고, 숫자아니고, 닫혀있다.
int marks_left = MAX_MARKS; // 남은 mark 횟수
int is_validMove(int row, int col);

void load_board(char* filename)
{
    FILE* fp;
    if (!(fp = fopen(filename, "r"))) {
        fprintf(stderr, "Fail to open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    //board 구성: M rows, N col, K cells where mine placed
    if (fscanf(fp, "%d %d %d", &M, &N, &K) != 3) {
        fprintf(stderr, "File format error\n");
        exit(EXIT_FAILURE);
    }

    //지뢰,지뢰 주변 좌표 및 정보 업데이트
    int row, col;
    int neighbor_row, neighbor_col;
    int x[] = { 1,1,0,-1,-1,-1,0,1 };
    int y[] = { 0,-1,-1,-1,0,1,1,1 };
    for (int i = 0; i < K; i++) {
        if (fscanf(fp, "%d %d", &row, &col) != 2) { //받은 인자 값이 2개 가 아닐경우 
            fprintf(stderr, "Error: File format\n");
            exit(EXIT_FAILURE);
        }
        board[row][col].mined = 1;
        board[row][col].num = 9; //지뢰 있는곳을 9이라 설정, 지뢰가 옆에 있을 최대 경우의 수는 8임 
        board[row][col].state = closed;
        for (int j = 0; j < 8; j++) {
            neighbor_row = row - x[j];
            neighbor_col = col - y[j];
            if (is_validMove(neighbor_row, neighbor_col) == 1 && board[neighbor_row][neighbor_col].mined != 1) {
                board[neighbor_row][neighbor_col].mined = 0;
                board[neighbor_row][neighbor_col].num += 1;
            }
        }
    }

    fclose(fp);
}

int is_validMove(int row, int col) {
    if (row >= 0 && row < M && col >= 0 && col < N) {
        return 1;
    }
    return 0;
}

int is_terminated()
{
    //지뢰가 열려있으면 종료해야됨
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j].mined == 1 && board[i][j].state == open) {
                return 1;
            }
        }
    }
    return 0;
}

void draw_board()
{
    printf("------------------------------------------\n");
    int col, row;
    for (row = 0; row < M; row++) {
        for (col = 0; col < N; col++) {
            switch (board[row][col].state)
            {
            case closed:
                printf("🔲"); //0:⬛0️⃣ 1:1️⃣ 2:2️⃣
                break;
            case marked:
                printf("🚩");
                break;
            case open:
                if (board[row][col].mined != 1) {
                    printf("%d ", board[row][col].num);
                    break;
                }
                printf("💥"); //지뢰일때
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

int is_in_queue(gqueue_t* rowQ, gqueue_t* colQ, int row, int col) {
    for (int i = 0; i < get_size(rowQ); i++) {
        int x;
        int y;
        get_elem(rowQ, i, &x);
        get_elem(colQ, i, &y);

        if (x == row && y == col) {
            return 1;
        }
    }
    return 0;
}

void setSafeZone(int row, int col) {
    gqueue_t* rowToSearch = create_queue(M * N, sizeof(int));
    gqueue_t* colToSearch = create_queue(M * N, sizeof(int));
    gqueue_t* nearby_row = create_queue(300, sizeof(int));
    gqueue_t* nearby_col = create_queue(300, sizeof(int));

    gqueue_t* rowToSet = create_queue(M * N, sizeof(int));
    gqueue_t* colToSet = create_queue(M * N, sizeof(int));

    if (rowToSearch == NULL || colToSearch == NULL) {
        fprintf(stderr, "Error: Queue is not initialized, check the code.\n");
        exit(EXIT_FAILURE);
    }

    //시계방향 탐색
    int add_row[] = { 0,1,1,1,0,-1,-1,-1 };
    int add_col[] = { 1,1,0,-1,-1,-1,0,1 };

    enqueue(rowToSearch, &row);
    enqueue(colToSearch, &col);

    int cur_row;
    int cur_col;
    int d = 0; //direction
    int nxt_row;
    int nxt_col;

    //0이 있는 덩어리 탐색후 그 부분 방문기록 남기기
    while (is_empty(rowToSearch) == 0) {
        dequeue(rowToSearch, &cur_row);
        dequeue(colToSearch, &cur_col);
        enqueue(rowToSet, &cur_row);
        enqueue(colToSet, &cur_col);

        for (d = 0; d < 8; d++) {
            nxt_row = cur_row + add_row[d];
            nxt_col = cur_col + add_col[d];

            if (is_validMove(nxt_row, nxt_col) == 1) {
                enqueue(nearby_row, &nxt_row);
                enqueue(nearby_col, &nxt_col);

                if (is_in_queue(rowToSet, colToSet, nxt_row, nxt_col) != 1 && board[nxt_row][nxt_col].num == 0) {
                    enqueue(rowToSearch, &nxt_row);
                    enqueue(colToSearch, &nxt_col);
                }

            }
        }
    }

    //safe부분에서 0부분 open처리

    for (int i = 0; i < get_size(rowToSet); i++) {
        int x;
        int y;
        dequeue(rowToSet, &x);
        dequeue(colToSet, &y);
        board[x][y].state = open;
    }


    //safe주변의 숫자들 open처리 
    int nby_row;
    int nby_col;

    while (is_empty(nearby_row) == 0) {
        dequeue(nearby_row, &nby_row);
        dequeue(nearby_col, &nby_col);
        //printf("dequeued\n");
        board[nby_row][nby_col].state = open;
    }

    //메모리 반납
    delete_queue(rowToSet);
    delete_queue(colToSet);
    delete_queue(nearby_row);
    delete_queue(nearby_col);
    return;
}

void read_execute_userinput()
{
    /* FIXME*/
    printf("[The command should be 'mark' or 'open']\n");
    printf("[example: open 1 1]\n\n");
    printf("Input command row col > ");

    char command[5];
    int col, row;

    if (scanf("%4s %d %d", command, &row, &col) != 3) {
        fprintf(stderr, "error: Invalid Input Value\n");
        return;
    }

    // 입력 좌표가 범위 내에 있는지 확인
    if (is_validMove(row, col)==0){
        fprintf(stderr, "error: Input coordinates out of range\n");
        return;
    }

    if (strcmp(command, "open") == 0) {  //문자열 일치
        if (board[row][col].state != open) {
            board[row][col].state = open;
            //when it is safe
            if (board[row][col].num == 0) {
                //change the state of nearby safe cells as 'open' 
                setSafeZone(row, col);
            }
        }
        else {
            fprintf(stderr, "error: the cell is already opened\n\n");
        }

    }
    else if (strcmp(command, "mark") == 0) {
        if (marks_left > 0) { // 남은 mark 횟수가 0보다 큰 경우에만 mark 가능
            if (board[row][col].state != marked) {
                board[row][col].state = marked;
                marks_left--; // mark를 사용하면 횟수 감소
                printf("Remaining marks: %d\n", marks_left);
                return;
            }
            board[row][col].state = closed; // 이미 마크되어 있으면 해제
            marks_left++; // 해제하면 횟수 증가
            printf("Remaining marks: %d\n", marks_left);
            return;
        }
        else {
            fprintf(stderr, "error: No marks left\n");
            return;
        }
    }
    else {
        fprintf(stderr, "error: Invalid input value\n");
        read_execute_userinput();
    }
}

void alarmhandler(int sig) {
    fprintf(stderr, "\n!!!!!TIMES UP!!!!!!\n");
    kill(getpid(), SIGKILL); //sigalrm이 울린 프로세스를 kill
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Invalid command: give a filename of board arrangement.\n");
        return EXIT_FAILURE;
    }

    load_board(argv[1]); //load board.txt

    //코드 상황 보려고 만들어 놓은거
    // for(int i = 0; i < 16; i++){
    //    for (int j = 0; j < 16; j++) {
    //       board[i][j].state = open;
    //    }
    // }

    struct timeval start_time, end_time;
    double elapsed_time;
    signal(SIGALRM, alarmhandler); //sigalrm이 발생하면 alarmhandler 작동

    //타이머 설정 (5*60초 지나면 프로세스 강제 종료)
    alarm(5 * 60);
    // 프로세스 시작 시간 기록
    gettimeofday(&start_time, NULL);



    while (!(is_terminated())) { //^c눌리면 종료
        draw_board(); //board 출력
        read_execute_userinput(); //좌표 선택
    }
    // 프로세스 종료 시간 기록
    gettimeofday(&end_time, NULL);
    // 경과 시간 계산
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    draw_board();
    printf("\n💥 you choose landmine!!\n");

    // 결과 출력
    printf("⏱️  Elapsed time: %f seconds\n", elapsed_time);


    return EXIT_SUCCESS;
}
