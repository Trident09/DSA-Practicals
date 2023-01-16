/* Traversal
    In-order traversal: Visit the left subtree, then the root, then the right subtree
    Pre-order traversal: Visit the root, then the left subtree, then the right subtree
    Post-order traversal: Visit the left subtree, then the right subtree, then the root */

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        this->root = nullptr;
    }

    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            std::cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node* root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            std::cout << root->data << " ";
        }
    }
};

int main() {
    Tree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    std::cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    std::cout << std::endl;
            
    std::cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    std::cout << std::endl;

    return 0;
}
