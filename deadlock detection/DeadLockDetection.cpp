#include <iostream>
#include <vector>
using namespace std;

// Function to check if all processes can finish
bool detectDeadlock(vector<vector<int>> &allocation, vector<vector<int>> &request, vector<int> &available) {
    int numProcesses = allocation.size();
    int numResources = available.size();

    // Initialize work and finish
    vector<int> work = available;
    vector<bool> finish(numProcesses, false);

    while (true) {
        bool progress = false;

        // Try to find a process that can execute
        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i]) {
                bool canExecute = true;
                for (int j = 0; j < numResources; j++) {
                    if (request[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    // If the process can execute, simulate its execution
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    progress = true;
                }
            }
        }

        // If no progress was made, break the loop
        if (!progress) break;
    }

    // Check if any process is unfinished (deadlock)
    for (bool f : finish) {
        if (!f) return true; // Deadlock detected
    }
    return false; // No deadlock
}

int main() {
    int numProcesses, numResources;

    // Input number of processes and resources
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    cout << "Enter the number of resources: ";
    cin >> numResources;

    // Input allocation matrix
    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input request matrix
    vector<vector<int>> request(numProcesses, vector<int>(numResources));
    cout << "Enter request matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> request[i][j];
        }
    }

    // Input available resources
    vector<int> available(numResources);
    cout << "Enter available resources:\n";
    for (int i = 0; i < numResources; i++) {
        cin >> available[i];
    }

    // Detect deadlock
    if (detectDeadlock(allocation, request, available)) {
        cout << "Deadlock detected!\n";
    } else {
        cout << "No deadlock.\n";
    }
system("pause");
    return 0;
}
