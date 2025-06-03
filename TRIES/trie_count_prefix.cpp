#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int prefixCount;
    bool isEndOfWord;
    vector<TrieNode*> children;
    TrieNode() : prefixCount(0), isEndOfWord(false), children(26, nullptr) {}
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
            currentNode->prefixCount++;
        }
        currentNode->isEndOfWord = true;
    }
    int countWordsWithPrefix(const string& prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return 0;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->prefixCount;
    }
};

int main() {
    Trie trie;
    trie.insertWord("test");
    trie.insertWord("tester");
    trie.insertWord("team");
    trie.insertWord("technical");
    cout << trie.countWordsWithPrefix("te") << "\n";
    cout << trie.countWordsWithPrefix("test") << "\n";
    cout << trie.countWordsWithPrefix("toast") << "\n";
    return 0;
}
