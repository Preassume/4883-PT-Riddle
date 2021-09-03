 /**
 * Austin Riddle
 * CMPS 4883
 * 9/7/2021
 */

#include <iostream>
#include <vector>

using namespace std;

// A simple struct to contain necessary data for the light cycle
// Also handles incrementation and checks for whether the light is green
struct light{
	int cycleTime;
	int greenTime;
	int curTime;
	
	// The constructor is supplied with the input from getScenario
	light(int time){
		cycleTime = time * 2; // The total time of the entire cycle
		greenTime = time - 5; // The time spent being green
		curTime = 0; // Our place in the cycle is initially zero
	}
	
	// If our current position in the cycle is within the time spent
	// being green, we return true. Otherwise, return false.
	bool isGreen(){
		return curTime < greenTime;
	}
	
	// Increment our position in the cycle. If we go over the cycle time,
	// then it is time to reset our position to zero again.
	void increment(){
		curTime++;
		if(curTime >= cycleTime) curTime = 0;
	}
};

// Get a scenario from input and store it into our light vector
// All traffic lights are green initially
bool getScenario(vector<light*>& lights){
	lights.clear();
	int tmp;
	cin >> tmp;
	if(tmp == 0) return false; // Return false if we reach the end of the input
	
	while(tmp != 0){
		lights.push_back(new light(tmp));
		cin >> tmp;
	}
	return true;
}

// Fast forward our scenario until the first light(s) become yellow
// After calling this function, it is no longer true that all lights are green.
int initScenario(vector<light*>& lights){
	int timer = 0;
	bool go = true;
	while(go){
		timer++;
		if(timer > 18000) break;
		
		for(auto x : lights){
			x->increment();
			if(!x->isGreen())
				go = false; // Stop looping when the first light(s) become yellow
		}
	}
	return timer;
}

// Now that not all lights are green, we increment until all lights are green again.
int simScenario(vector<light*>& lights){
	int timer = 0;
	bool go = true;
	while(go){
		timer++;
		if(timer > 18000) break;
		
		go = false;
		for(auto x : lights){
			x->increment();
			
			if(x->isGreen() == false)
				go = true; // Keep looping until all lights are green
		}
	}
	return timer;
}

// Convert our result from seconds into hh:mm:ss format and print it
void printTime(int totalSeconds){
	if(totalSeconds > 18000){
		cout << "Signals fail to synchronise in 5 hours\n";
		return;
	}
	int seconds = totalSeconds;
	
	int minutes = totalSeconds / 60;
	seconds -= minutes * 60;
	
	int hours = minutes / 60;
	minutes -= hours * 60;
	
	cout << '0' << hours << ':';
	
	if(minutes < 10) cout << '0';
	cout << minutes << ':';
	
	if(seconds < 10) cout << '0';
	cout << seconds << '\n';
}

int main(){
	vector<light*> lights; // Will hold one scenario at a time
	
	while(getScenario(lights)){ // Get one scenario from input
		
		//Initialize the scenario, then run the simulation. Save the time taken
		int totalTime = initScenario(lights) + simScenario(lights);
		
		printTime(totalTime); // Print the result
	}
}
