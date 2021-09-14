/**
 * Austin Riddle
 * 4883
 * 9/14/2021
 */

// This is still work in progress, so I haven't cleaned up and commented it yet. Sorry.

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int junctions, streets, disconJunctions;
bool debug = false; // Set this to true for a more verbose output

bool isBipartite(vector<vector<bool>>& adj, int src, vector<int>& colorVec){
	colorVec[src] = 1;
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		if(adj[u][u] == 1)
			return false;
		
		for(int v = 0; v < junctions; ++v){
			if(adj[u][v] && colorVec[v] == -1){
				colorVec[v] = 1 - colorVec[u];
				q.push(v);
			}
			else if(adj[u][v] && colorVec[v] == colorVec[u])
				return false;
		}
	}
	return true;
}

int getNumGuards(vector<vector<bool>>& adj){
	vector<int> colorVec;
	colorVec.resize(junctions, -1);
	
	for(int i = 0; i < junctions; i++)
		if(colorVec[i] == -1)
			if(!isBipartite(adj, i, colorVec))
				return -1;
	
	int counter = 0;
	for(auto x : colorVec){
		if(x == 1) counter++;
		if(debug) cout << x << ' ';
	}
	if(debug) cout << "| ";
	if(counter == 0) return 1;
	
	int dif = junctions - counter;
	if(counter > dif) return dif;
	return counter;
}

vector<vector<bool>> getAdjMatrix(){
	vector<vector<bool>> adj;
	set<int> input;
	
	adj.resize(junctions);
	for(int i = 0; i < junctions; i++){
		adj[i].resize(junctions, false);
	}
	
	int f, t;
	for(int i = 0; i < streets; i++){
		cin >> f >> t;
		input.insert(f);
		input.insert(t);
		adj[f][t] = true;
		adj[t][f] = true;
	}
	disconJunctions = junctions - input.size();
	return adj;
}

int main(){
	int tests;
	
	cin >> tests;
	
	int counter = 1;
	while(tests){
		
		cin >> junctions >> streets;
		
		if(streets == 0){
			if(debug) cout << counter << ":\n" << junctions << ' ' << streets << '\n';
			cout << junctions << '\n';
			if(debug) cout << '\n';
		}
		else{
			auto adjMat = getAdjMatrix();
			if(debug){
				cout << counter << ":\n" << junctions << ' ' << streets << '\n';
				for(auto x : adjMat){
					for(auto y : x){
						cout << y << ' ';
					}
					cout << '\n';
				}
			}
			int guards = getNumGuards(adjMat);
			if(guards == -1) cout << guards << '\n';
			else cout << guards + disconJunctions << '\n';
			if(debug){
				cout << guards << ' ' << disconJunctions << '\n';
			}
			if(debug) cout << '\n';
		}
		tests--;
		counter++;
	}
}
