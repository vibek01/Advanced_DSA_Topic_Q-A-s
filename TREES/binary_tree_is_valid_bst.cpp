#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

BSTNode* findMinNode(BSTNode* root) {
    BSTNode* currentNode = root;
    while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

BSTNode* deleteFromBST(BSTNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->key) {
        root->left = deleteFromBST(root->left, key);
    } else if (key > root->key) {
        root->right = deleteFromBST(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        } else {
            BSTNode* successor = findMinNode(root->right);
            root->key = successor->key;
            root->right = deleteFromBST(root->right, successor->key);
        }
    }
    return root;
}

int main() {
    BSTNode* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = (root == nullptr) ? new BSTNode(val) : root;
        if (root->key != val) {
            BSTNode* temp = root;
            while (true) {
                if (val < temp->key) {
                    if (temp->left == nullptr) {
                        temp->left = new BSTNode(val);
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else if (val > temp->key) {
                    if (temp->right == nullptr) {
                        temp->right = new BSTNode(val);
                        break;
                    } else {
                        temp = temp->right;
                    }
                } else {
                    break;
                }
            }
        }
    }
    root = deleteFromBST(root, 3);
    return 0;
}
