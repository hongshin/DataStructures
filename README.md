# Island

Write a program that reads a map of island(s) and then prints out the number of islands, the minimum and the maximum areas of the islands.

**Preliminaries**

* A map is a 2D array where each cell indicates whether the corresponding coordinate is land (1) or ocean (0).
* A man can move from a cell to another cell when both cells are of land and they share one border (i.e., adjacent)
* An island is a maximum set of land cells where a man can reach from one member cell to another member cell
* The area of an island is the number of member cells


**Input**

* Given from the standard input
* First line contains two integers *W* and *H* for 1 ≤ *W* ≤20 and 1≤ *H* ≤20. *W* represents the width and *H* the height of the map.
* From second line to (*H*+1)-th line, each line has *W* integers to represent the map.  The *x*-th number at (*y*+1)-th line represents whether the (*y*, *x*) cell is land or ocean
* The map contains at leaset one island

**Output**

* Print the number of islands, the minimum area among the islands and the maximum area among the islands
* Make sure to put newline (‘\n’) at the end

**Example**

* Input
	```
	8 8 
	0 1 1 0 0 1 1 0
	0 1 1 0 0 0 0 0
	0 0 1 0 0 1 1 0
	0 1 0 0 0 1 1 0
	0 1 1 0 0 1 1 0
	0 1 1 0 1 1 1 0
	0 1 1 0 0 1 1 0
	0 1 1 0 0 1 1 0 
	```

* Output
	```
	4 2 13
	```
