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
    bool startsWith(const string& prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insertWord("hello");
    trie.insertWord("helium");
    cout << trie.startsWith("he") << "\n";
    cout << trie.startsWith("ho") << "\n";
    return 0;
}
