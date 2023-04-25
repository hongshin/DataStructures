#include <cstdlib>
#include <iostream>
#include <string>

#include "linkedlist.h"

using namespace std ;

int dy[8] = {-2, -2, -1, -1,  1,  1 , 2,  2} ;
int dx[8] = {-1,  1, -2,  2, -2,  2, -1,  1} ;


class Loc {
	public :
		int y ;
		int x ;

		Loc () {} 
		Loc (int y, int x) ;
		~Loc () {} ;
} ;

Loc::Loc (int y, int x)
{
	this->y = y ;
	this->x = x ;
}

ostream& operator<<(ostream &out, const Loc& n)
{
	out << n.y << "," << n.x ;
	return out ;
}


Loc * prevloc[8][8] = { 0x0 } ;

void print_move (Loc curr, Loc begin)
{
	LinkedList<Loc> * path = new LinkedList<Loc>() ;	
	do {
		path->addFirst(&curr) ;
		curr = *(prevloc[curr.y][curr.x]) ;
	} while (curr.y != begin.y || curr.x != begin.x) ;
	path->addFirst(&begin) ;

	path->print() ;

	delete path ;
}

int main ()
{
	LinkedList<Loc> * worklist = new LinkedList<Loc>() ;

	Loc begin(1, 2) ;
	Loc dest(1, 7) ;

	worklist->addLast(&begin) ;
	prevloc[1][2] = &begin ;

	while (!worklist->empty()) {
		Loc curr ;
		worklist->removeFirst(&curr) ;

		if (curr.y == dest.y && curr.x == dest.x) {
			print_move(curr, begin) ;
			return 0 ;
		}

		for (int i = 0 ; i < 8 ; i++) {
			Loc next(curr.y + dy[i], curr.x + dx[i]) ;
			if (0 <= next.x && next.x < 8 && 0 <= next.y && next.y < 8) {
				if (prevloc[next.y][next.x] == 0x0) {
					prevloc[next.y][next.x] = new Loc(curr.y, curr.x) ; 
					worklist->addLast(&next) ;
				}
			}

		}
	}

	delete worklist ;

	return 0 ;
}
