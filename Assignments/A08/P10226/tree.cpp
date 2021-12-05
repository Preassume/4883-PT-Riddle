/**
 * Austin Riddle
 * 4883
 * 9/20/2021
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

#define ulint unsigned long int
#define ldub long double

using namespace std;

ulint totalTrees; // Keeps us from having to loop through our map twice

// Goes through every species input in one test case and counts how many
// trees of each species there are
map<string, ldub> getTrees(){
	string species, tmp;
	
	totalTrees = 0; // Reset totalTrees for each test case
	
	map<string, ldub> speciesCount;
	
	while(true){
		getline(cin, species);
		
		if(species == "") // If we read a blank line, we're done with this test case
			return speciesCount; // Return our resulting map
		
		speciesCount[species]++; // Increment that species type
		totalTrees++; // Increment our total tree count;
	}
}

int main(){
	int iterations;
	string tmpStr;
	
	// Get number of test cases and initialize getline's position in the input
	cin >> iterations;
	getline(cin, tmpStr);
	getline(cin, tmpStr);
	
	// Make sure our percentages are always displayed to 4 decimal places
	cout << fixed << setprecision(4);
	
	while(iterations--){
		auto speciesCount = getTrees();
		
		// Get the percentage of each species and display it with its name
		for(auto x : speciesCount){
			double percentage = (x.second / totalTrees) * 100;
			cout << x.first << ' ' << percentage << '\n';
		}
		
		if(iterations > 0) 
			cout << '\n'; // No need for the extra line at the final test case
	}
}
