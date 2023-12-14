#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr)
            return new TreeNode(key);

        if (key < root->val)
            root->left = insert(root->left, key);
        else if (key > root->val)
            root->right = insert(root->right, key);

        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    TreeNode* search(TreeNode* root, int key) {
        if (root == nullptr || root->val == key)
            return root;

        if (key < root->val)
            return search(root->left, key);

        return search(root->right, key);
    }

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            std::cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }

    void preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            std::cout << root->val << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            std::cout << root->val << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.inorder();
    std::cout << "Preorder Traversal: ";
    bst.preorder();
    std::cout << "Postorder Traversal: ";
    bst.postorder();

    bst.deleteKey(30);
    std::cout << "After deleting 30:" << std::endl;
    std::cout << "Inorder Traversal: ";
    bst.inorder();

    return 0;
}
