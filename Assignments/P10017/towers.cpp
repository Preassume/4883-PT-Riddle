/**
 * Austin Riddle
 * 4883
 * 9/28/2021
 */

#include <iostream>
#include <map>
#include <stack>
#include <vector>

#define peg stack<int>

using namespace std;

int counter;
vector<peg> pegs;

// Prints the contents of all of the pegs.
void printPegs(){
    char pegLetter = 'A';
    for(auto x : pegs){
        cout << pegLetter << "=>";
        
        if(!x.empty()) // Only need the spaces when there are contents
			cout << "   ";

        peg tmpPeg; // New peg to reverse the order for correct printing

        while(!x.empty()){ // Does not destroy the contents of the peg
            tmpPeg.push(x.top());
            x.pop();
        }
        while(!tmpPeg.empty()){
            cout << tmpPeg.top();
            
            if(tmpPeg.size() > 1) // Makes sure there's not an extra space at the end
				cout << ' ';
            
            tmpPeg.pop();
        }

        cout << '\n';
        pegLetter++;
    }
    cout << '\n';
}

// A simple function that moves the top element from the source stack to
// the top of the destination stack.
void moveDisk(int from, int to){
    int disk = pegs[from].top();
    pegs[from].pop();
    pegs[to].push(disk);
    printPegs();
}

// A simple recursive algorithm to solve the Towers of Hanoi.
// Only solves up to the number of moves specified in the input.
void solveTowers(int disk, int from, int to, int aux){
    if(counter <= 0)
        return;
    
    if(disk == 1){
        --counter;
        moveDisk(from, to);
        return;
    }

    solveTowers(disk - 1, from, aux, to); // Swap aux and destination
    if(counter <= 0)
        return;
    --counter;
    moveDisk(from, to);
    solveTowers(disk - 1, aux, to, from);
}

int main(){
    pegs.resize(3); // Create three pegs

    int elements, problemCounter = 0;

    while(cin >> elements){
        cin >> counter;
        
        if(counter == 0 && elements == 0)
            return 0;

        problemCounter++;
        cout << "Problem #" << problemCounter << "\n\n";

        // Clear the pegs for the new problem
        for(auto &x : pegs)
            while(!x.empty())
                x.pop();

        for(int i = elements; i > 0; i--){
            pegs[0].push(i);
        }
        printPegs();
        solveTowers(elements, 0, 2, 1);
    }
}
