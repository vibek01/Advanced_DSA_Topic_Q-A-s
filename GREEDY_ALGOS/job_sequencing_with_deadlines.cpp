#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> jobs(n);
    for (int i = 0; i < n; i++) {
        int deadline, profit;
        cin >> deadline >> profit;
        jobs[i] = {profit, deadline};
    }

    sort(jobs.begin(), jobs.end(), greater<>());

    int maxDeadline = 0;
    for (auto& j : jobs) {
        maxDeadline = max(maxDeadline, j.second);
    }

    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int countJobs = 0;

    for (auto& j : jobs) {
        for (int t = j.second; t > 0; t--) {
            if (!slot[t]) {
                slot[t] = true;
                totalProfit += j.first;
                countJobs++;
                break;
            }
        }
    }

    cout << countJobs << " " << totalProfit << "\n";
    return 0;
}
