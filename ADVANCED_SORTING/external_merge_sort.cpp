#include <bits/stdc++.h>
using namespace std;

void mergeFiles(const vector<string>& tempFiles, const string& outputFile) {
    int k = tempFiles.size();
    vector<ifstream> inputs(k);
    for (int i = 0; i < k; i++) {
        inputs[i].open(tempFiles[i]);
    }
    ofstream output(outputFile);
    vector<int> values(k);
    vector<bool> hasValue(k, false);
    for (int i = 0; i < k; i++) {
        if (inputs[i] >> values[i]) {
            hasValue[i] = true;
        }
    }
    while (true) {
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (hasValue[i] && values[i] < minValue) {
                minValue = values[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) break;
        output << minValue << "\n";
        if (inputs[minIndex] >> values[minIndex]) {
            hasValue[minIndex] = true;
        } else {
            hasValue[minIndex] = false;
        }
    }
    for (int i = 0; i < k; i++) {
        inputs[i].close();
    }
    output.close();
}

void externalMergeSort(const string& inputFile, const string& outputFile, int chunkSize) {
    ifstream input(inputFile);
    vector<string> tempFiles;
    vector<int> buffer;
    int value;
    int fileCount = 0;
    while (input >> value) {
        buffer.push_back(value);
        if (buffer.size() == chunkSize) {
            sort(buffer.begin(), buffer.end());
            string tempName = "temp" + to_string(fileCount) + ".txt";
            ofstream tempOut(tempName);
            for (int x : buffer) {
                tempOut << x << "\n";
            }
            tempOut.close();
            tempFiles.push_back(tempName);
            buffer.clear();
            fileCount++;
        }
    }
    if (!buffer.empty()) {
        sort(buffer.begin(), buffer.end());
        string tempName = "temp" + to_string(fileCount) + ".txt";
        ofstream tempOut(tempName);
        for (int x : buffer) {
            tempOut << x << "\n";
        }
        tempOut.close();
        tempFiles.push_back(tempName);
        buffer.clear();
    }
    input.close();
    mergeFiles(tempFiles, outputFile);
    for (auto& name : tempFiles) {
        remove(name.c_str());
    }
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    int chunkSize = 1000;
    externalMergeSort(inputFile, outputFile, chunkSize);
    return 0;
}
