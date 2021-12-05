/**
 * Austin Riddle
 * 4883
 * 9/21/2021
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// A simple struct that holds all relevant data about a game from input
struct game{
	string team1, team2;
	int score1, score2;
};

// This structure stores all relevant data for a team. It has methods 
// to allow for easy data entering.
struct team{
	int rank, points, games, wins, ties, losses, goalDiff, goalsScored, goalsAgainst;
	string name;
	
	team(){
		name = "";
		rank = points = games = wins = ties = losses = goalDiff = goalsScored = goalsAgainst = 0;
	}
	
	team(string n){
		name = n;
		rank = points = games = wins = ties = losses = goalDiff = goalsScored = goalsAgainst = 0;
	}
	
	// Give this team a victory. Worth 3 points
	void victory(){
		points += 3;
		wins += 1;
		games += 1;
	}
	
	// Give this team a tie. Worth 1 point.
	void tie(){
		points += 1;
		ties += 1;
		games += 1;
	}
	
	// Give this team a loss. Worth no points.
	void defeat(){
		losses += 1;
		games += 1;
	}
	
	// Increment goals scored and against, and calculate the difference.
	void addGoals(int scored, int against){
		goalsScored += scored;
		goalsAgainst += against;
		goalDiff = goalsScored - goalsAgainst;
	}
	
	// Print the contents of this team in the desired format.
	void print(){
		cout << rank << ") "
			<< name << ' '
			<< points << "p, "
			<< games << "g ("
			<< wins << '-' << ties << '-' << losses
			<< "), " << goalDiff << "gd ("
			<< goalsScored << '-' << goalsAgainst << ")\n";
	}
};

// Grab a single integer from input and getline to keep things straight
int getInt(){
	string tmp;
	int num;
	cin >> num;
	getline(cin, tmp);
	return num;
}

// Get the game data from one line of input and store it into a game struct
game getGame(string s){
	game theGame;
	
	int hashCounter = 0;
	for(char x : s){
		if(x == '#' || x == '@'){
			hashCounter++;
		}
		else if(hashCounter == 0){
			theGame.team1 += x;
		}
		else if(hashCounter == 1){
			theGame.score1 = x - '0';
		}
		else if(hashCounter == 2){
			theGame.score2 = x - '0';
		}
		else if(hashCounter == 3){
			theGame.team2 += x;
		}
	}
	return theGame;
}

// Initialize our teams map with the list of team names from the input
map<string, team> getTeams(){
	map<string, team> teams;
	
	int numTeams = getInt();
	
	while(numTeams--){
		string line;
		getline(cin, line);
		teams[line] = team(line);
	}
	return teams;
}

// Gets all of the game data and stores it into a vector.
// Then, we go through that vector, adding its contents to our team structs. 
vector<team> getTeamStats(map<string, team> teams){
	int numGames = getInt();
	
	// Get game data
	vector<game> games;
	while(numGames--){
		string line;
		getline(cin, line);
		games.push_back(getGame(line));
	}
	
	// Load up our team structs
	for(auto x : games){
		teams[x.team1].addGoals(x.score1, x.score2);
		teams[x.team2].addGoals(x.score2, x.score1);
		
		if(x.score1 > x.score2){
			teams[x.team1].victory();
			teams[x.team2].defeat();
		}
		else if(x.score1 < x.score2){
			teams[x.team1].defeat();
			teams[x.team2].victory();
		}
		else if(x.score1 == x.score2){
			teams[x.team1].tie();
			teams[x.team2].tie();
		}
	}
	
	// Store our team data into a vector so that it can be sorted
	vector<team> teamsVec;
	
	for(auto x : teams){
		teamsVec.push_back(x.second);
	}
	
	return teamsVec;
}

// Returns the all lower-case version of a string
string lowerCase(string& s){
	string lower = s;
	for(auto& c : lower){
		if(c >= 65 && c <= 90){
			c += 32;
		}
	}
	return lower;
}

// A comparison function to be used with a sort function. Allows us to sort by
// points earned, most wins, most goal difference, most goals scored, 
// less games played, and finally lexicographic order.
bool compareTeams(team t1, team t2){
	if(t1.points == t2.points){
		if(t1.wins == t2.wins){
			if(t1.goalDiff == t2.goalDiff){
				if(t1.goalsScored == t2.goalsScored){
					if(t1.games == t2.games){
						return lowerCase(t1.name).compare(lowerCase(t2.name)) < 0;
					}
					return t1.games < t2.games;
				}
				return t1.goalsScored > t2.goalsScored;
			}
			return t1.goalDiff > t2.goalDiff;
		}
		return t1.wins > t2.wins;
	}
	return t1.points > t2.points;
}

int main(){
	int numCups = getInt();
	
	while(numCups--){
		string line;
		getline(cin, line);
		cout << line << '\n';
		
		auto teams = getTeamStats(getTeams());
		
		stable_sort(teams.begin(), teams.end(), compareTeams);
		
		for(int i = 0; i < (int)teams.size(); i++){
			teams[i].rank = i + 1;
			teams[i].print();
		}
		if(numCups > 0) cout << '\n';
	}
}
