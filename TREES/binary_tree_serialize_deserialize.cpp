#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void serializeTree(TreeNode* root, ostream& out) {
    if (root == nullptr) {
        out << "# ";
        return;
    }
    out << root->data << " ";
    serializeTree(root->left, out);
    serializeTree(root->right, out);
}

TreeNode* deserializeTree(istringstream& in) {
    string token;
    if (!(in >> token)) return nullptr;
    if (token == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(token));
    node->left = deserializeTree(in);
    node->right = deserializeTree(in);
    return node;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    ostringstream outStream;
    serializeTree(root, outStream);
    string serializedData = outStream.str();

    istringstream inStream(serializedData);
    TreeNode* deserializedRoot = deserializeTree(inStream);

    return 0;
}
