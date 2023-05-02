# Lab 7. Academic Family Tree #

Academic genealogy is represented as a family tree where *X* becomes the parent of *Y* if *X* advises *Y* in *Y*'s doctoral degree.
Assume that each person has at most one advisor (i.e., parent)
Write a program that receives advisor-advisee relation and then prints the academic family tree (see the example below)

* Example
	- Input
		```
		10 8
		Park Kim
		Park Lee
		Hwang Park
		Lee Woo
		Lee Nam
		Hwang Choi
		Choi Hong
		Koh Wang
		```
	- Output
		```
		+Hwang
		|   +--Park
   	 	|   |   +--Kim
   		|   |   +--Lee
		|   |       +--Woo
		|   |       +--Nam
		|   +--Choi
   		|       +--Hong
		+Koh
		    +--Wang
		```

* Input

First line has two numbers *N* and *M* (0 < *N* ≤ 100,  0 < *M* ≤ 10000) , where *N* represents the number of scholars and *M* represents the number of advise relations.
From second line, each line has *X* and *Y* where *X* is the advisor and *Y* is the advisee. The name of a scholar is a string without a blank. The length of a name is always less than 64.

* Output

Print out ``error`` if the given input is invalid. Given valid input, the output must be formed as follows:
    - An advisor must be printed earlier than an advisee. 
    - The indendation of an advisee must be one level higher than its advisor. And, the indendation should be decorated as given in the example
    - Bar (``|``) connects two siblings when they are seperated.
