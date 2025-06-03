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
    void collectWords(TrieNode* node, string& currentWord, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(currentWord);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                currentWord.push_back('a' + i);
                collectWords(node->children[i], currentWord, result);
                currentWord.pop_back();
            }
        }
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
    vector<string> autocomplete(const string& prefix) {
        vector<string> result;
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return result;
            }
            currentNode = currentNode->children[index];
        }
        string currentWord = prefix;
        collectWords(currentNode, currentWord, result);
        return result;
    }
};

int main() {
    Trie trie;
    vector<string> words = {"apple", "app", "apt", "banana", "band", "bandana"};
    for (const string& w : words) {
        trie.insertWord(w);
    }
    vector<string> suggestions = trie.autocomplete("ban");
    for (const string& s : suggestions) {
        cout << s << "\n";
    }
    return 0;
}
