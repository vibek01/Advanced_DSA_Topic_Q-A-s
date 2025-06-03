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
    TrieNode* getRoot() {
        return root;
    }
};

int rows, cols;
vector<vector<bool>> visited;
set<string> foundWords;
vector<string> resultWords;
int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };

void dfsGrid(int i, int j, TrieNode* node, string& currentStr, vector<vector<char>>& board) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        return;
    }
    if (visited[i][j]) {
        return;
    }
    char ch = board[i][j];
    int index = ch - 'a';
    if (node->children[index] == nullptr) {
        return;
    }
    visited[i][j] = true;
    currentStr.push_back(ch);
    node = node->children[index];
    if (node->isEndOfWord) {
        if (!foundWords.count(currentStr)) {
            foundWords.insert(currentStr);
            resultWords.push_back(currentStr);
        }
    }
    for (int dir = 0; dir < 4; dir++) {
        int newRow = i + dRow[dir];
        int newCol = j + dCol[dir];
        dfsGrid(newRow, newCol, node, currentStr, board);
    }
    currentStr.pop_back();
    visited[i][j] = false;
}

vector<string> findWordsInGrid(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (const string& w : words) {
        trie.insertWord(w);
    }
    rows = board.size();
    cols = board[0].size();
    visited.assign(rows, vector<bool>(cols, false));
    TrieNode* root = trie.getRoot();
    string currentStr;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dfsGrid(i, j, root, currentStr, board);
        }
    }
    return resultWords;
}

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain", "hike"};
    vector<string> found = findWordsInGrid(board, words);
    for (const string& w : found) {
        cout << w << "\n";
    }
    return 0;
}
