## 11080 - Place the Guards
### Austin Riddle
### Description:

In the country of Ajabdesh there are some streets and junctions. Each street connects 2 junctions. The king of Ajabdesh wants to place some guards in some junctions so that all the junctions and streets can be guarded by them. A guard in a junction can guard all the junctions and streets adjacent to it. But the guards them- selves are not gentle. If a street is guarded by multiple guards then they start fighting. So the king does not want the scenario where a street may be guarded by two guards. Given the information about the streets and junctions of Ajabdesh, help the king to find the minimum number of guards needed to guard all the junctions and streets of his country.

I was able to solve this problem by modifying some bipartite-detection code from https://www.geeksforgeeks.org/bipartite-graph/. The primary modification was to the isBipartiteUtil function (which I shortened to isBipartite in my program.) This function was modified to keep track of the changes made to the colors vector each time the function is called. We can determine which color set contains the fewest elements for that particular function call and we return that value. The values returned from this function are added together, and this sum is the smallest number of guards required to guard every junction. If the data is found to not be a bipartite graph, then we return -1 and that is all that is printed. This is because if the graph is not bipartite, then it is impossible to guard every junction without causing fights amongst the guards.

Basically, my program grabs the input, creates an adjacency matrix out of it, and runs it through my modified geeksforgeeks functions. This produces the minimum number of guards required to guard every junction without fighting.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[guard.cpp](./guard.cpp) | Solution Source Code.                    |
|   2   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   3   |[11080.pdf](./11080.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile guard.cpp and run the executable. ```g++ guard.cpp -o guard```
- To supply the input file, run it like this: ```./guard < data.dat```
- To output to a file, run it like this: ```./guard < data.dat > out.txt``` (out.txt can be anything you want)

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/
- Geeks for Geeks
    - https://www.geeksforgeeks.org/bipartite-graph/
