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

// Function to request resources for a process
bool requestResources(int processID, vector<int> &request, vector<vector<int>> &allocation, vector<vector<int>> &maxNeed, vector<int> &available) {
    int numResources = available.size();

    // Check if the request exceeds the maximum need
    for (int j = 0; j < numResources; ++j) {
        if (request[j] > maxNeed[processID][j] - allocation[processID][j]) {
            cout << "Error: Process " << processID << " is requesting more than its maximum need.\n";
            return false;
        }
    }

    // Check if the request exceeds the available resources
    for (int j = 0; j < numResources; ++j) {
        if (request[j] > available[j]) {
            cout << "Error: Not enough available resources for process " << processID << ".\n";
            return false;
        }
    }

    // Pretend to allocate resources
    for (int j = 0; j < numResources; ++j) {
        available[j] -= request[j];
        allocation[processID][j] += request[j];
    }

    // Check if the system remains in a safe state
    vector<int> safeSequence;
    if (isSafeState(allocation, maxNeed, available, safeSequence)) {
        cout << "Request granted. Safe sequence: ";
        for (int process : safeSequence) {
            cout << "P" << process << " ";
        }
        cout << endl;
        return true;
    } else {
        // Rollback if not safe
        for (int j = 0; j < numResources; ++j) {
            available[j] += request[j];
            allocation[processID][j] -= request[j];
        }
        cout << "Request denied. System would enter an unsafe state.\n";
        return false;
    }
}

int main() {
    int numProcesses, numResources;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    cout << "Enter the number of resources: ";
    cin >> numResources;

    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    vector<vector<int>> maxNeed(numProcesses, vector<int>(numResources));
    vector<int> available(numResources);

    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter maximum need matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> maxNeed[i][j];
        }
    }

    cout << "Enter available resources:\n";
    for (int j = 0; j < numResources; j++) {
        cin >> available[j];
    }

    vector<int> safeSequence;
    if (isSafeState(allocation, maxNeed, available, safeSequence)) {
        cout << "System is initially in a safe state. Safe sequence: ";
        for (int process : safeSequence) {
            cout << "P" << process << " ";
        }
        cout << endl;
    } else {
        cout << "System is not in a safe state initially.\n";
    }

    while (true) {
        cout << "Enter process ID to request resources (-1 to exit): ";
        int processID;
        cin >> processID;
        if (processID == -1) break;

        cout << "Enter resource request vector:\n";
        vector<int> request(numResources);
        for (int j = 0; j < numResources; j++) {
            cin >> request[j];
        }

        requestResources(processID, request, allocation, maxNeed, available);
    }
    system("pause");
    return 0;
}
