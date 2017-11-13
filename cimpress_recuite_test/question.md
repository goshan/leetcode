# Find an equal point in a string of brackets

Given a string of brackets, the task is to find an index k which decides the number of opening brackets is equal to the number of closing brackets.
String must be consists of only opening and closing brackets i.e. ‘(‘ and ‘)’.

An equal point is an index such that the number of opening brackets before it is equal to the number of closing brackets from and after.

Examples:

```
Input : str = "(())))("
Output:   4
After index 4, string splits into (())
and ))(. Number of opening brackets in the 
first part is equal to number of closing 
brackets in the second part.

Input : str = "))"
Output: 2
As after 2nd position i.e. )) and "empty"
string will be split into these two parts:
So, in this number of opening brackets i.e.
0 in the first part is equal to number of 
closing brackets in the second part i.e. 
also 0.
```
