/* The basic operations that can be performed on a BST are:

    Insertion: Adding a new node to the tree
    Deletion: Removing a node from the tree
    Searching: Finding a node with a specific value
    Traversal: Visiting all the nodes of the tree in a specific order (e.g. in-order, pre-order, post-order) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// insert a new node in the tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// search for a node with a specific value
bool search(struct Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    if (root->data < data) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

// in-order traversal of the tree (left-root-right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In-order traversal of the tree: ");
    inOrder(root);
    printf("\n");
    int search_for = 70;
    if (search(root, search_for)) {
        printf("Found %d in the tree\n", search_for);
    } else {
        printf("%d not found in the tree\n", search_for);
    }
    return 0;
}
