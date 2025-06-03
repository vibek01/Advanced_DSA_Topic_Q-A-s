#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

BSTNode* findMinNode(BSTNode* root) {
    if (root == nullptr) return nullptr;
    BSTNode* currentNode = root;
    while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

BSTNode* findMaxNode(BSTNode* root) {
    if (root == nullptr) return nullptr;
    BSTNode* currentNode = root;
    while (currentNode->right != nullptr) {
        currentNode = currentNode->right;
    }
    return currentNode;
}

int main() {
    BSTNode* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        if (root == nullptr) {
            root = new BSTNode(val);
        } else {
            BSTNode* temp = root;
            while (true) {
                if (val < temp->key) {
                    if (temp->left == nullptr) {
                        temp->left = new BSTNode(val);
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = new BSTNode(val);
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    BSTNode* minNode = findMinNode(root);
    BSTNode* maxNode = findMaxNode(root);
    if (minNode != nullptr) cout << "Min: " << minNode->key << endl;
    if (maxNode != nullptr) cout << "Max: " << maxNode->key << endl;
    return 0;
}
