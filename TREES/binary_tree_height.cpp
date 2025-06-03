#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int computeTreeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftHeight = computeTreeHeight(root->left);
    int rightHeight = computeTreeHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << computeTreeHeight(root);
    return 0;
}
