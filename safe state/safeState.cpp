#include <iostream>
#include <vector>
using namespace std;

// Function to check if the system is in a safe state
bool isSafeState(vector<vector<int>> &allocation, vector<vector<int>> &maxNeed, vector<int> &available, vector<int> &safeSequence) {
    int numProcesses = allocation.size();
    int numResources = available.size();

    vector<int> work = available;
    vector<bool> finish(numProcesses, false);
    safeSequence.clear();

    for (int count = 0; count < numProcesses; ++count) {
        bool found = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < numResources; ++j) {
                    if (maxNeed[i][j] - allocation[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < numResources; ++j) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            return false; // System is not in a safe state
        }
    }
    return true; // System is in a safe state
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

    // Input maximum need matrix
    vector<vector<int>> maxNeed(numProcesses, vector<int>(numResources));
    cout << "Enter maximum need matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> maxNeed[i][j];
        }
    }

    // Input available resources
    vector<int> available(numResources);
    cout << "Enter available resources:\n";
    for (int j = 0; j < numResources; j++) {
        cin >> available[j];
    }

    // Check if the system is in a safe state
    vector<int> safeSequence;
    if (isSafeState(allocation, maxNeed, available, safeSequence)) {
        cout << "System is in a safe state. Safe sequence: ";
        for (int process : safeSequence) {
            cout << "P" << process << " ";
        }
        cout << endl;
    } else {
        cout << "System is not in a safe state.\n";
    }
system("pause");
    return 0;
}
