#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEndOfWord;
    vector<TrieNode*> children;
    TrieNode() : isEndOfWord(false), children(26, nullptr) {}
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
        }
        currentNode->isEndOfWord = true;
    }
    bool searchWord(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isEndOfWord;
    }
    bool canFormByConcatenation(const string& word) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) {
                continue;
            }
            TrieNode* currentNode = root;
            for (int j = i; j < n; j++) {
                int index = word[j] - 'a';
                if (currentNode->children[index] == nullptr) {
                    break;
                }
                currentNode = currentNode->children[index];
                if (currentNode->isEndOfWord) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    vector<string> dict = {"cat", "cats", "dog", "sand", "and", "catdog"};
    Trie trie;
    for (const string& w : dict) {
        trie.insertWord(w);
    }
    vector<string> testWords = {"catsdog", "dogcats", "sanddog", "catsand"};
    for (const string& w : testWords) {
        cout << w << ": " << trie.canFormByConcatenation(w) << "\n";
    }
    return 0;
}
