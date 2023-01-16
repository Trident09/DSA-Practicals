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

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// get the height of a node
int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// get the balance factor of a node
int getBalance(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// rotate a node to the left
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

// rotate a node to the right
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

// insert a new node in the tree
struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// search for a node with a specific value
bool search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data < data)
    {
        return search(root->right, data);
    }
    else
    {
        return search(root->left, data);
    }
}

// in-order traversal of the tree (left-root-right)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf("In-order traversal of the tree: ");
    inOrder(root);
    printf("\n");
    int search_for = 30;
    if (search(root, search_for))
    {
        printf("Found %d in the tree\n", search_for);
    }
    else
    {
        printf("%d not found in the tree\n", search_for);
    }
    return 0;
}
