#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

/*TODO: add functions if necessary for Task 3*/

typedef struct {
		char * title ;
		int year ;
		int month ;	
	} 
	movie_t ;


movie_t movies[] = {
    {"G.I. Joe: Retaliation", 2013, 3},
    {"After Yang", 2021, 3},
    {"Entourage", 2015, 6},
    {"The Knight Before Christmas", 2019, 11},
    {"Thor", 2011, 5},
    {"Survival Island", 2005, 5},
    {"Encanto", 2021, 11},
    {"Doctor Sleep", 2019, 11},
    {"King Arthur: Legend of the Sword", 2017, 5},
    {"Wolf Creek", 2005, 12},
    {"Saw", 2004, 10},
    {"Papillon", 2017, 8},
    {"No Sudden Move", 2021, 7},
    {"Lucy", 2014, 7},
    {"Bridesmaids", 2011, 5},
    {"Bad Times at the El Royale", 2018, 10},
    {"Jojo Rabbit", 2019, 11},
    {"Million Dollar Baby", 2004, 1},
    {"The League of Extraordinary Gentlemen", 2003, 7},
    {"The Fabelmans", 2022, 11},
    {"Barbarian", 2022, 9},
    {"Baby Driver", 2017, 6},
    {"The Danish Girl", 2015, 1},
    {"Open Water", 2003, 8},
    {"Fantasy Island", 2020, 2},
    {"Noroi", 2005, 6},
    {"Roman J. Israel, Esq.", 2017, 11},
    {"Date Night", 2010, 4},
    {"Operation Mincemeat", 2021, 5},
    {"Raising Helen", 2004, 5},
    {"The School for Good and Evil", 2022, 10},
    {"Semi-Pro", 2008, 2},
    {"The Reader", 2008, 1},
    {"Elf", 2003, 11},
    {"Ice Age: The Meltdown", 2006, 3},
    {"Kingsman: The Golden Circle", 2017, 9},
    {"The Way Back", 2010, 1},
    {"Cold Mountain", 2003, 12},
    {"The Constant Gardener", 2005, 8},
    {"The Switch", 2010, 8},
    {"The Lodge", 2019, 1},
    {"Shazam!", 2019, 4},
    {"Lizzie", 2018, 9},
    {"Silent Hill", 2006, 4},
    {"The Twilight Saga: Breaking Dawn - Part 2", 2012, 11},
    {"Wild Child", 2008, 8},
    {"The Prestige", 2006, 10},
    {"The Visit", 2015, 9},
    {"The Christmas Candle", 2013, 11}
    {"Hugo", 2011, 11}
} ;

int 
main ()
{

	// print out the movies in ''movies'' in ascending order. 
	// A movie precedes another movie if it released earlier than the other one. 
	// Or, if both released at the same month, a movie precedes the other one if its title lexicographically precedes.
	
	/*TODO: revise this function for Task 3*/

	return 0 ;
}
