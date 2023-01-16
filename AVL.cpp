/* The basic operations that can be performed on an AVL tree are:

    Insertion: Adding a new node to the tree
    Deletion: Removing a node from the tree
    Searching: Finding a node with a specific value
    Traversal: Visiting all the nodes of the tree in a specific order (e.g. in-order, pre-order, post-order)
  When a new node is inserted into an AVL tree, the tree is checked for balance after each insertion. If the tree becomes unbalanced, a rotation is performed to restore the balance property. There are four types of rotations that can be performed on an AVL tree:

    Left Rotation
    Right Rotation
    Left-Right Rotation
    Right-Left Rotation */

#include <iostream>

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->height = 1;
        this->left = this->right = nullptr;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        this->root = nullptr;
    }

    int height(Node* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));
        return x;
    }
    Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));
    return y;
}

Node* insert(Node* node, int data) {
    if (!node) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
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
AVLTree tree;
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
