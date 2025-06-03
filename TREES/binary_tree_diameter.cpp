#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int computeDiameterHelper(TreeNode* node, int& maxDiameter) {
    if (node == nullptr) return 0;
    int leftHeight = computeDiameterHelper(node->left, maxDiameter);
    int rightHeight = computeDiameterHelper(node->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int computeDiameter(TreeNode* root) {
    int maxDiameter = 0;
    computeDiameterHelper(root, maxDiameter);
    return maxDiameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << computeDiameter(root);
    return 0;
}
