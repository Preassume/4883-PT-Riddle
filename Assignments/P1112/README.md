## 1112 - Mice and Maze
### Austin Riddle
### Description:

A set of laboratory mice is being trained to escape a maze. The maze is made up of cells, and each cell
is connected to some other cells. However, there are obstacles in the passage between cells and therefore
there is a time penalty to overcome the passage Also, some passages allow mice to go one-way, but not
the other way round.
Suppose that all mice are now trained and, when placed in an arbitrary cell in the maze, take a
path that leads them to the exit cell in minimum time.
We are going to conduct the following experiment: a mouse is placed in each cell of the maze and
a count-down timer is started. When the timer stops we count the number of mice out of the maze.
Write a program that, given a description of the maze and the time limit, predicts the number of
mice that will exit the maze. Assume that there are no bottlenecks is the maze, i.e. that all cells have
room for an arbitrary number of mice.

To solve this problem, I first tried using a breadth-first search to try to get the distances to the exit. I soon realized that a BFS would not give the correct answer for a weighted graph such as the one in this problem. So, I switched to using Dijkstra's algorithm.

My implementations of Dijkstra's algorithm were over-complicated and didn't work properly, and at some point I realized that using an adjacency matrix that contains the distances between each node would be much simpler. Even with that, I had trouble writing my own implementation from scratch. Luckily I found a nice example that also uses a matrix (2D array) to store the graph, and that helped me understand the algorithm much better.

Even after all that, what I ended up with was a way of calculating the distances from the exit node to all the other nodes, which is kind of useless for this problem. This was a simple fix. By reversing the "from" and "to" values from the connection inputs, I was able to effectively calculate the distance from all the other nodes to the exit. At that point, all that is needed is to count how many of those distances are less than or equal to the time limit.

### Files


|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [mice.cpp](./mice.cpp)     | Solution Source Code.                                      |
|   2   | [data.dat](./data.dat)     | Test input file from uDebug.                               |
|   3   | [1112.pdf](./1112.pdf)     | Original problem description document.                     |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile mice.cpp and run the executable. ```g++ mice.cpp -o mice```
- To supply the input and output to a file, run it like this: ```./mice < data.dat```

### Sources

- Wikipedia
    - https://en.wikipedia.org/wiki/Breadth-first_search
    - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
- Free Code Camp
    - https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/
- Geeks for Geeks
    - https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

I used these sources to try to understand how these algorithms work so that I could use them to solve the problem.
