#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string code, unordered_map<char,string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

int main() {
    string text;
    getline(cin, text);
    unordered_map<char,int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freqMap) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node(left, right);
        pq.push(merged);
    }

    Node* root = pq.top();

    unordered_map<char,string> codes;
    buildCodes(root, "", codes);

    for (auto& p : codes) {
        cout << p.first << ":" << p.second << "\n";
    }

    return 0;
}
