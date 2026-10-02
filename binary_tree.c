#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {
    int data;
    struct tree *lchild;
    struct tree *rchild;
};

typedef struct tree * TREE;

TREE getnode() {
    TREE x = (TREE)malloc(sizeof(struct tree));
    if (x == NULL) {
        printf("No memory allocated!\n");
        exit(1);
    }
    return x;
}

TREE insert(int data, TREE root) {
    TREE temp, cur, prev;
    char path[20];
    int i, len;

    temp = getnode();
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if (root == NULL) {
        return temp;
    }

    printf("Enter the path of insertion (e.g., L, R, LR): ");
    scanf("%s", path);
    len = strlen(path);

    prev = NULL;
    cur = root;

    for (i = 0; i < len && cur != NULL; i++) {
        prev = cur;
        if (path[i] == 'l' || path[i] == 'L') {
            cur = cur->lchild;
        } else if (path[i] == 'r' || path[i] == 'R') {
            cur = cur->rchild;
        } else {
            printf("Invalid character in path!\n");
            free(temp);
            return root;
        }
    }

        printf("Insertion is not possible along this path.\n");
        free(temp);
        return root;
    }

    char last_step = path[len - 1];
    if (last_step == 'l' || last_step == 'L') {
        prev->lchild = temp;
    } else {
        prev->rchild = temp;
    }

    return root;
}

void preorder(TREE root) {
    if (root != NULL) {
        printf("\t%d", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(TREE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("\t%d", root->data);
        inorder(root->rchild);
    }
}

void postorder(TREE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("\t%d", root->data);
    }
}

void search(int data, TREE root, int *flag) {
    if (root != NULL && *flag == 0) {
        if (data == root->data) {
            *flag = 1;
            return;
        }
        search(data, root->lchild, flag);
        search(data, root->rchild, flag);
    }
}

int main() {
    TREE root = NULL;
    int choice, data, flag;

    while (1) {
        printf("\n\n--- MAIN MENU ---");
        printf("\n1. Insert into the tree");
        printf("\n2. Preorder traversal");
        printf("\n3. Inorder traversal");
        printf("\n4. Postorder traversal");
        printf("\n5. Search for an item");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &data);
                root = insert(data, root);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    printf("Preorder traversal:\n");
                    preorder(root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    printf("Inorder traversal:\n");
                    inorder(root);
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    printf("Postorder traversal:\n");
                    postorder(root);
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    printf("Enter item to be searched: ");
                    scanf("%d", &data);
                    flag = 0;
                    search(data, root, &flag);
                    if (flag == 1) {
                        printf("Search successful: %d found in tree.", data);
                    } else {
                        printf("Search unsuccessful: %d not found.", data);
                    }
                }
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.");
                break;
        }
    }

    return 0;
}
