#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int wordCount;
    vector<TrieNode*> children;
    TrieNode() : wordCount(0), children(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insertWord(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
            currentNode->wordCount++;
        }
    }
    string longestCommonPrefix(int totalWords) {
        string prefix;
        TrieNode* currentNode = root;
        while (true) {
            int countChildren = 0;
            int childIndex = -1;
            for (int i = 0; i < 26; i++) {
                if (currentNode->children[i] != nullptr && currentNode->children[i]->wordCount == totalWords) {
                    countChildren++;
                    childIndex = i;
                }
            }
            if (countChildren == 1) {
                prefix.push_back('a' + childIndex);
                currentNode = currentNode->children[childIndex];
            } else {
                break;
            }
        }
        return prefix;
    }
};

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    Trie trie;
    for (const string& w : words) {
        trie.insertWord(w);
    }
    cout << trie.longestCommonPrefix(words.size());
    return 0;
}
