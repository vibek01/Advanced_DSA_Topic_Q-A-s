#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int value1, int value2) {
    if (root == nullptr) return nullptr;
    if (root->data == value1 || root->data == value2) return root;
    TreeNode* leftLCA = findLCA(root->left, value1, value2);
    TreeNode* rightLCA = findLCA(root->right, value1, value2);
    if (leftLCA != nullptr && rightLCA != nullptr) return root;
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    TreeNode* lcaNode = findLCA(root, 4, 5);
    if (lcaNode != nullptr) cout << lcaNode->data;
    return 0;
}
