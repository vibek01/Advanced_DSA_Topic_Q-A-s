#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEndOfWord;
    vector<TrieNode*> children;
    TrieNode() : isEndOfWord(false), children(26, nullptr) {}
};

class WordDictionary {
private:
    TrieNode* root;
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (index == word.size()) {
            return node->isEndOfWord;
        }
        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(const string& word) {
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
    bool search(const string& word) {
        return searchHelper(word, 0, root);
    }
};

int main() {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("pad") << "\n";
    cout << dict.search("bad") << "\n";
    cout << dict.search(".ad") << "\n";
    cout << dict.search("b..") << "\n";
    return 0;
}
