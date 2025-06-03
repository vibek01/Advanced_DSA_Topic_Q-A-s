#include <bits/stdc++.h>
using namespace std;

void lsdRadixSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> output(n);
    for (int shift = 0; shift < 32; shift += 8) {
        vector<int> count(256, 0);
        for (int i = 0; i < n; i++) {
            int byteValue = (arr[i] >> shift) & 0xFF;
            count[byteValue]++;
        }
        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int byteValue = (arr[i] >> shift) & 0xFF;
            output[count[byteValue] - 1] = arr[i];
            count[byteValue]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    lsdRadixSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
