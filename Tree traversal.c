/* Traversal
    In-order traversal: Visit the left subtree, then the root, then the right subtree
    Pre-order traversal: Visit the root, then the left subtree, then the right subtree
    Post-order traversal: Visit the left subtree, then the right subtree, then the root */

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

// in-order traversal (left-root-right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// pre-order traversal (root-left-right)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// post-order traversal (left-right-root)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\nPre-order traversal: ");
    preOrder(root);
    printf("\nPost-order traversal: ");
    postOrder(root);

    return 0;
}
