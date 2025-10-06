#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}

void towerHanoi(int numDisks, string source, string buffer, string target, int& numMoves) {
    // safeguard: invalid input
    if (numDisks <= 0) {
        throw invalid_argument("Number of disks must be positive.");
    }

    // optional safeguard: prevent excessive recursion depth
    const int MAX_SAFE_DISKS = 20;
    if (numDisks > MAX_SAFE_DISKS) {
        cerr << "Warning: numDisks exceeds safe recursion limit (" << MAX_SAFE_DISKS << ")." << endl;
        return;
    }

    // base case: only one disk to move
    if (numDisks == 1) {
        cout << "Moving disc 1 from " << source << " to " << target << endl;
        numMoves++;
        return;
    }

    // recursive case:
    // Step 1: move n-1 disks from source to buffer using target
    towerHanoi(numDisks - 1, source, target, buffer, numMoves);

    // Step 2: move the nth disk from source to target
    cout << "Moving disc " << numDisks << " from " << source << " to " << target << endl;
    numMoves++;

    // Step 3: move n-1 disks from buffer to target using source
    towerHanoi(numDisks - 1, buffer, source, target, numMoves);
}