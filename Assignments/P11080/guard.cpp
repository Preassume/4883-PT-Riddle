/**
 * Austin Riddle
 * 4883
 * 9/14/2021
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int junctions, streets;
bool debug = false; // Set this to true for a more verbose output

// Returns a -1 if a graph is not bipartite. Else, returns the number of elements
// in the smallest set of colors possible.
// This function is based on code found at https://www.geeksforgeeks.org/bipartite-graph/
int isBipartite(vector<vector<bool>>& adj, int src, vector<int>& colorVec){
	colorVec[src] = 1;
	
	// We must create a vector to keep track of the changes we made to colorVec
	// during this function call. This is used to calculate the minimum number of guards.
	vector<int> tmpColors;
	tmpColors.resize(junctions, -1);
	tmpColors[src] = 1; // We mimic every change done to colorVec
	
	// We use this map to keep track of the changes made to colorVec during this function call
	map<bool, int> changeCount;
	changeCount[1]++; // We changed an element in colorVec to 1, so we keep count of that
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		if(adj[u][u] == 1)
			return -1;
		
		for(int v = 0; v < junctions; ++v){
			if(adj[u][v] && colorVec[v] == -1){
				colorVec[v] = 1 - colorVec[u];
				changeCount[colorVec[v]]++; // Increment our counters in our map
				q.push(v);
			}
			else if(adj[u][v] && colorVec[v] == colorVec[u])
				return -1;
		}
	}
	
	// We want to return the number of elements in the smallest non-zero set of colors
	if(changeCount[0] > 0 && changeCount[1] > 0)
		return min(changeCount[0], changeCount[1]);
		
	else if(changeCount[0] > 0)
		return changeCount[0];
		
	else if(changeCount[1] > 0)
		return changeCount[1];
		
	return 0;
}

// This function will return the minimum number of guards required.
// If it is not possible to guard every junction, it returns -1.
// This function is based on code found at https://www.geeksforgeeks.org/bipartite-graph/
int getNumGuards(vector<vector<bool>>& adj){
	vector<int> colorVec;
	colorVec.resize(junctions, -1);
	
	int guardCount = 0;
	for(int i = 0; i < junctions; i++)
		if(colorVec[i] == -1){
			int tmp = isBipartite(adj, i, colorVec);
			if(tmp == -1) return -1;
			guardCount += tmp;
		}
	return guardCount;
}

// This creates the adjacency matrix based on the input
vector<vector<bool>> getAdjMatrix(){
	vector<vector<bool>> adj;
	
	adj.resize(junctions);
	for(int i = 0; i < junctions; i++){
		adj[i].resize(junctions, false);
	}
	
	int f, t;
	for(int i = 0; i < streets; i++){
		cin >> f >> t;
		adj[f][t] = true;
		adj[t][f] = true;
	}
	return adj;
}

int main(){
	int tests;
	
	cin >> tests;
	
	int counter = 1;
	while(tests){
		cin >> junctions >> streets;
		auto adjMat = getAdjMatrix();
		
		if(debug){ // Verbose output if global variable 'debug' is true
			cout << '\n' << counter << ":\n";
			cout << junctions << ' ' << streets << '\n';
			
			// Print the adjacency matrix
			for(auto x : adjMat){
				for(auto y : x){
					cout << y << ' ';
				}
				cout << '\n';
			}
			counter++;
		}
		
		// If we have no streets, then we must have one guard for each junction
		if(streets == 0){
			cout << junctions << '\n';
		}
		else{
			cout << getNumGuards(adjMat) << '\n';
		}
		
		tests--;
	}
}
