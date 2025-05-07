#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    char jobId;
    int deadline, profit;
};

// Comparator to sort jobs in descending order of profit
bool comparison(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(Job arr[], int n) {
    // Sort jobs by decreasing profit
    sort(arr, arr + n, comparison);

    // Find maximum deadline to determine number of slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }

    // Initialize time slots as free
    vector<bool> slot(maxDeadline, false);
    vector<char> result(maxDeadline);
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from last possible slot)
        for (int j = min(maxDeadline, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = arr[i].jobId;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Jobs selected: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << "\nMax Profit is: " << maxProfit << "\n";
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job* arr = new Job[n]; // dynamic allocation
    cout << "Enter job details (JobID Deadline Profit):\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> arr[i].jobId >> arr[i].deadline >> arr[i].profit;
    }

    jobScheduling(arr, n);

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
