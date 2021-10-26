## 10226 - Hardwood Species & 10194 - Football aka Soccer
### Austin Riddle
### Hardwood Species Description:

Hardwoods are the botanical group of trees that have broad leaves, produce a fruit or nut, and generally go dormant in the winter. America’s temperate climates produce forests with hundreds of hardwood species —trees that share certain biological characteristics. Although oak, maple and cherry all are types of hardwood trees, for example, they are different species. Together, all the hardwood species represent 40 percent of the trees in the United States. On the other hand, softwoods, or conifers, from the Latin word meaning “cone-bearing”, have needles. Widely available US softwoods include cedar, fir, hemlock, pine, redwood, spruce and cypress. In a home, the softwoods are used primarily as structural lumber such as 2×4s and 2×6s, with some limited decorative applications. Using satellite imaging technology, the Department of Natural Resources has compiled an inventory of every tree standing on a particular day. You are to compute the total fraction of the tree population represented by each species.

My hardwood species code found in tree.cpp is working great. I used a std::map container to keep track of the tree species. The key is the species name and the value is the number of times that species has occurred. Something to note is that I used a long double to keep track of the number of species. This allowed for a decimal approximation of the percentages of each species to be generated.


### Soccer aka Football Description:

Football the most popular sport in the world (americans insist to call it “Soccer”, but we will call it “Football”). As everyone knows, Brasil is the country that have most World Cup titles (four of them: 1958, 1962, 1970 and 1994). As our national tournament have many teams (and even regional tournaments have many teams also) it’s a very hard task to keep track of standings with so many teams and games played! So, your task is quite simple: write a program that receives the tournament name, team names and games played and outputs the tournament standings so far. A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3 points for each win, 1 point for each tie and 0 point for each loss. Teams are ranked according to these rules (in this order):
1. Most points earned.
2. Most wins.
3. Most goal difference (i.e. goals scored - goals against)
4. Most goals scored.
5. Less games played.
6. Lexicographic order.

I haven't yet been able to get a correct submission with my soccer program. Everything I have tested seems to give the correct answer, so I think this will likely remain a mystery to me.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[tree.cpp](./tree.cpp)               | Hardwood Species solution source code.   |
|   2   |[treedata.dat](./treedata.dat)       | Test input file from uDebug for Hardwood Species|
|   3   |[10226.pdf](./10226.pdf)             | Hardwood Species problem description document.   |
|   4   |[soccer.cpp](./soccer.cpp)               | Soccer aka Football solution source code.|
|   5   |[soccerdata.dat](./soccerdata.dat)               | Test input file from uDebug for Soccer aka Football|
|   6   |[10194.pdf](./10194.pdf)             | Soccer aka Football problem description document.|
### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile tree.cpp and run the executable. ```g++ tree.cpp -o tree```
- To supply the input file, run it like this: ```./tree < treedata.dat```
- To output to a file, run it like this: ```./tree < treedata.dat > out.txt``` (out.txt can be anything you want)
- For the soccer program, substitute ```tree.cpp``` with ```soccer.cpp``` and ```treedata.dat``` with ```soccerdata.dat```.

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/

