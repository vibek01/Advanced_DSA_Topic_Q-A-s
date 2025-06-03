#include <bits/stdc++.h>
using namespace std;

void countingSortByChar(vector<string>& arr, int index) {
    int n = arr.size();
    vector<int> count(257, 0);
    vector<string> output(n);
    for (int i = 0; i < n; i++) {
        int c = index < arr[i].size() ? (unsigned char)arr[i][index] + 1 : 0;
        count[c]++;
    }
    for (int i = 1; i < 257; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int c = index < arr[i].size() ? (unsigned char)arr[i][index] + 1 : 0;
        output[count[c] - 1] = arr[i];
        count[c]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSortVariableStrings(vector<string>& arr) {
    int maxLength = 0;
    for (auto& s : arr) {
        if (s.size() > maxLength) {
            maxLength = s.size();
        }
    }
    for (int i = maxLength - 1; i >= 0; i--) {
        countingSortByChar(arr, i);
    }
}

int main() {
    vector<string> arr = {"apple", "app", "banana", "band", "bandana", "apricot"};
    radixSortVariableStrings(arr);
    for (auto& s : arr) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}
