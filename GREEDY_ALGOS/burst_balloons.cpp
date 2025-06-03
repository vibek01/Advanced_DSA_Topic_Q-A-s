#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> balloons(n);
    for (int i = 0; i < n; i++) {
        cin >> balloons[i].first >> balloons[i].second;
    }

    sort(balloons.begin(), balloons.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });

    int arrows = 0;
    int lastPoint = INT_MIN;

    for (auto& b : balloons) {
        if (b.first > lastPoint) {
            arrows++;
            lastPoint = b.second;
        }
    }

    cout << arrows << "\n";
    return 0;
}
