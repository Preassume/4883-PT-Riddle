 /**
 * Austin Riddle
 * CMPS 4883
 * 11/02/2021
 */
#include <iostream>

using namespace std;

int main(){
	int cases, walls, height, highJumps, lowJumps, counter = 0;
	cin >> cases;
	while(cases--){
		lowJumps = 0;
		highJumps = 0;
		counter++;
		
		cout << "Case " << counter << ": ";
		
		cin >> walls;
		cin >> height; // Get the first wall
		walls--;
		
		while(walls--){
			int tmp;
			cin >> tmp;
			
			if(tmp > height) highJumps++;
			else if(tmp < height) lowJumps++;
			
			height = tmp; // Keep track of one previous wall height
		}
		cout << highJumps << ' ' << lowJumps << '\n';
	}
}
