#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
} *new_node, *temp;


struct node* create(int data)
{
    new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->lchild = NULL;
    new_node->rchild = NULL;

    return new_node;
}

// Global index to track the array position
int idx = -1;

struct node* buildTree(int nodes[]) {
    idx++;

    // -1 represents a null (empty) node
    if (nodes[idx] == -1) {
        return NULL;
    }

    // Create the node using your custom function
    struct node* root_node = create(nodes[idx]);

    // Recursively build the left and right subtrees using your lchild and rchild
    root_node->lchild = buildTree(nodes);
    root_node->rchild = buildTree(nodes);

    return root_node;
}

int main() {
    // Array representing preorder traversal (1 is root, 2 is left child, etc.)
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    struct node* root = buildTree(nodes);

    // Quick test to verify it worked
    if (root != NULL) {
        printf("The root node is: %d\n", root->data);
        printf("The root's left child is: %d\n", root->lchild->data);
        printf("The root's right child is: %d\n", root->rchild->data);
    }

    return 0;
}
