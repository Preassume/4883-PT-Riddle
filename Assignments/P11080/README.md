# Assignment 7

### Austin Riddle

#### For CMPS 4883 Programming Techniques.

#### 09/14/2021

This is problem __11080__ from https://onlinejudge.org/ called __Place the Guards__.

I was able to solve this problem by modifying some bipartite-detection code from https://www.geeksforgeeks.org/bipartite-graph/.  The primary modification was to the ```isBipartiteUtil``` function (which I shortened to ```isBipartite``` in my program.)  This function was modified to keep track of the changes made to the colors vector each time the function is called.  We can determine which color set contains the fewest elements for that particular function call and we return that value.  The values returned from this function are added together, and this sum is the smallest number of guards required to guard every junction.  If the data is found to not be a bipartite graph, then we return -1 and that is all that is printed.  This is because if the graph is not bipartite, then it is impossible to guard every junction without causing fights amongst the guards.


Basically, my program grabs the input, creates an adjacency matrix out of it, and runs it through my modified geeksforgeeks functions.  This produces the minimum number of guards required to guard every junction without fighting.
