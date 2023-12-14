#include <iostream>
#include <algorithm>

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return (node != nullptr) ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // Duplicate keys not allowed in this example

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->key) {
                // Left-Left Case
                return rotateRight(node);
            } else {
                // Left-Right Case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (key > node->right->key) {
                // Right-Right Case
                return rotateLeft(node);
            } else {
                // Right-Left Case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    AVLNode* search(AVLNode* node, int key) {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }
};

int main() {
    AVLTree avl;

    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(40);
    avl.insert(60);
    avl.insert(80);

    std::cout << "Search for 40: " << (avl.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 90: " << (avl.search(90) ? "Found" : "Not Found") << std::endl;

    return 0;
}
