/**
 * Austin Riddle
 * 4883
 * 10/26/2021
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int numCells;

vector<vector<int>> cells; // Cell adjacency matrix with distances

// Get the minimum distance values from the vertices not yet visited
int minDist(vector<int>& distance, vector<bool>& visited){
	int cellNum, min = INT_MAX;
	
	for(int i = 0; i < numCells; i++){
		if(visited[i] == false && distance[i] <= min){
			min = distance[i];
			cellNum = i;
		}
	}
	return cellNum;
}

// Dijkstra's algorithm:
// Finds the shortest distances to every vertex from the root vertex
vector<int> dijkstra(int root){
	vector<bool> visited;
	visited.resize(numCells, false);
	
	// Initially, all distances are INT_MAX to represent infinity
	vector<int> distance;
	distance.resize(numCells, INT_MAX);
	
	distance[root] = 0;
	
	for(int i = 0; i < numCells - 1; i++){
		// Set u equal to the closest cell we haven't been to yet
		int u = minDist(distance, visited);
		
		visited[u] = true; // Now we've visited it
		
		// Iterate through our neighbors and update their distance values
		for(int v = 0; v < numCells; v++){
			if (!visited[v] && cells[u][v] && distance[u] != INT_MAX && distance[u] + cells[u][v] < distance[v])
				distance[v] = distance[u] + cells[u][v];
		}
	}
	return distance;
}

int main(){
	int runs;
	cin >> runs;
	
	while(runs--){
		int exitCell, timer, connections;
		cin >> numCells >> exitCell >> timer >> connections;
		exitCell--; // Decrement so we can count cells from zero
		
		// Initialize distance matrix
		cells.clear();
		cells.resize(numCells, vector<int>(numCells, 0));
		
		while(connections--){
			int cell1, cell2, travelTime;
			cin >> cell1 >> cell2 >> travelTime;
			
			// Start cell counting at zero instead for simplicity's sake
			cell1--;
			cell2--;
			
			// I'm swapping cell2 and cell1 here because mice can't backtrack,
			// and calculating the distance to travel FROM the exit is useless.
			// So, swapping them gives us all the paths that go TO the exit.
			cells[cell2][cell1] = travelTime;
		}
		auto mouseTimes = dijkstra(exitCell);
		
		int counter = 0; // Number of mice that make it out in time
		
		for(auto x : mouseTimes){
			if(x <= timer) counter++;
		}
		cout << counter << '\n';
		if(runs > 0) cout << '\n';
	}
}
