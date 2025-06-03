#include <bits/stdc++.h>
using namespace std;

int main() {
    int universeSize;
    cin >> universeSize;
    int setCount;
    cin >> setCount;

    vector<unordered_set<int>> sets(setCount);
    for (int i = 0; i < setCount; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            sets[i].insert(x);
        }
    }

    unordered_set<int> covered;
    vector<int> chosenSets;

    while (covered.size() < universeSize) {
        int bestIndex = -1;
        int maxCover = 0;
        for (int i = 0; i < setCount; i++) {
            int countNew = 0;
            for (int x : sets[i]) {
                if (!covered.count(x)) {
                    countNew++;
                }
            }
            if (countNew > maxCover) {
                maxCover = countNew;
                bestIndex = i;
            }
        }
        chosenSets.push_back(bestIndex);
        for (int x : sets[bestIndex]) {
            covered.insert(x);
        }
        sets[bestIndex].clear();
    }

    cout << chosenSets.size() << "\n";
    for (int idx : chosenSets) {
        cout << idx << " ";
    }
    cout << "\n";
    return 0;
}
