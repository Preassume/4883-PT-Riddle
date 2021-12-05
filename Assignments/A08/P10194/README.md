## 10194 - Football aka Soccer
### Austin Riddle
### Description:

Football the most popular sport in the world (americans insist to call it “Soccer”, but we will call it “Football”). As everyone knows, Brasil is the country that have most World Cup titles (four of them: 1958, 1962, 1970 and 1994). As our national tournament have many teams (and even regional tournaments have many teams also) it’s a very hard task to keep track of standings with so many teams and games played! So, your task is quite simple: write a program that receives the tournament name, team names and games played and outputs the tournament standings so far. A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3 points for each win, 1 point for each tie and 0 point for each loss. Teams are ranked according to these rules (in this order):
1. Most points earned.
2. Most wins.
3. Most goal difference (i.e. goals scored - goals against)
4. Most goals scored.
5. Less games played.
6. Lexicographic order.

I haven't yet been able to get a correct submission with my soccer program. Everything I have tested from uDebug seems to give the correct answer, so I think this will likely remain a mystery to me.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[soccer.cpp](./soccer.cpp) | Solution source code.                    |
|   2   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   3   |[10194.pdf](./10194.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile soccer.cpp and run the executable. ```g++ soccer.cpp -o soccer```
- To supply the input file, run it like this: ```./soccer < data.dat```
- To output to a file, run it like this: ```./soccer < data.dat > out.txt``` (out.txt can be anything you want)

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/

