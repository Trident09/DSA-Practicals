/* The basic operations that can be performed on a BST are:

    Insertion: Adding a new node to the tree
    Deletion: Removing a node from the tree
    Searching: Finding a node with a specific value
    Traversal: Visiting all the nodes of the tree in a specific order (e.g. in-order, pre-order, post-order) */

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

class BST {
public:
    Node* root;

    BST() {
        this->root = nullptr;
    }

    Node* insert(Node* node, int data) {
        if (!node) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            std::cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void insert(int data) {
        root = insert(root, data);
    }
};

int main() {
    BST tree;
    tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);
    std::cout << "In-order traversal of the tree: ";
    tree.inOrder(tree.root);
    return 0;
}
