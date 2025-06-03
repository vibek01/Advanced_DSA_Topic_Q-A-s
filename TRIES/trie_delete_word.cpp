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
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (node == nullptr) {
            return false;
        }
        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                for (int i = 0; i < 26; i++) {
                    if (node->children[i] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            if (!node->isEndOfWord) {
                for (int i = 0; i < 26; i++) {
                    if (node->children[i] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
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
    void deleteWord(const string& word) {
        deleteHelper(root, word, 0);
    }
};

int main() {
    Trie trie;
    trie.insertWord("abc");
    trie.insertWord("abcd");
    cout << trie.searchWord("abc") << "\n";
    trie.deleteWord("abc");
    cout << trie.searchWord("abc") << "\n";
    cout << trie.searchWord("abcd") << "\n";
    return 0;
}
