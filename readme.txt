COMP 2510 - Assignment 3 - Records

Takes records from standard in and prints it back to standard out.
Can specify command-line arguments for sort order. 
+ = ascending order
- = descending order
n = sort by name
s = sort by score

Runs in:

./rsort.exe [argument1] [argument2]

argument1 - (optional)
argument2 - (optional)

e.g valid arguments:
rsort +n -s
rsort -n +s
rsort +n +s
rsort +s -n

e.g invalid arguments:
rsort +s -s
rsort +n -n
rsort +n -s -n

rsort -s +n sorts in descending order of scores; if two or more records have the same score, they are
then sorted in ascending order of their names.

rsort +n -s sorts in ascending order of names; if two or more records have the same name, they are
then sorted in descending order of their scores.