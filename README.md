# Programming Assignment 2. Substring Reverse

### Attributes
* Type: Individual work (you cannot collaborate with other students)
* Due date: 9 PM, 14 Apr (Fri) 2023 KST
* Rules: Only the C programming language reference, the earlier lab results, and the main textbook are allowed for your reference in doinig this homework. You are not allowed to see existing source code and to use other programming assistant tools; You must write down all source code by yourself.

### Description

A substring reverse operation makes a part of a given string reversed, while the oter parts remain. For example, a string `123456789` becomes `345176982`:

* reverse the substring that starts at index 1 and ends at 4 (i.e., `2345`)
* reverse the substring that starts at index 4 and ends at 6 (i.e., `267`)
* reverse the substring that starts at index 6 and ends at 8 (i.e., `289`)
* reverse the substring that starts at index 0 and ends at 3 (i.e., `1543`)

This assignment asks you to write a program that receives two strings `s1` and `s2`, and then finds a sequence of substring reverse operations that transforms `s1` into `s2`. 
The followings are a list of specific requirements or assugmptions of this programming assignments:
* use the given stack library (`stack.c` and `llist.c`),
* assume that the length of the given string does not exceed 64,
* print out the solution (i.e., a sequence of substring reverse operations) legibly,
* limit the length of a substring reverse operation sequence to the length of the given string. Print `no solution` if  no solution is found under the limit, 
* you must write a 1-page document to explain how to use your program.

Submit your result to HDLMS by 9 PM, 14 Apr (Fri). No late submission will be accepted.

Your results will be evaluated by test cases, and also you may take in-person interview if needed. 
