#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].second >> activities[i].first;
    }

    sort(activities.begin(), activities.end());

    int countSelected = 1;
    int lastFinish = activities[0].first;
    for (int i = 1; i < n; i++) {
        if (activities[i].second > lastFinish) {
            countSelected++;
            lastFinish = activities[i].first;
        }
    }

    cout << countSelected << "\n";
    return 0;
}
