#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

BSTNode* insertIntoBST(BSTNode* root, int value) {
    if (root == nullptr) return new BSTNode(value);
    if (value < root->key) {
        root->left = insertIntoBST(root->left, value);
    } else if (value > root->key) {
        root->right = insertIntoBST(root->right, value);
    }
    return root;
}

bool searchInBST(BSTNode* root, int target) {
    if (root == nullptr) return false;
    if (root->key == target) return true;
    if (target < root->key) {
        return searchInBST(root->left, target);
    } else {
        return searchInBST(root->right, target);
    }
}

int main() {
    BSTNode* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insertIntoBST(root, val);
    }
    cout << (searchInBST(root, 4) ? "Found" : "Not Found");
    return 0;
}
