#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });

    vector<int> points;
    for (auto& iv : intervals) {
        if (points.empty() || iv.first > points.back()) {
            points.push_back(iv.second);
        }
    }

    cout << points.size() << "\n";
    for (int p : points) {
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}
