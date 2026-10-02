#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL, *temp, *new, *tail;

// 1. Create List
void create() {
    int value;
    char ch;

    do {
        new = (struct node *)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);

        new->data = value;
        new->next = NULL;

        if (head == NULL) {
            head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = new;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

// 2. Display List
void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 3. Insert at Beginning
void insertAtBeg() {
    int value;

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    new->data = value;
    new->next = head;
    head = new;

    if (tail == NULL) {
        tail = new;
    }

    printf("Node inserted at beginning successfully.\n");
}

// 4. Insert at End
void insertAtEnd() {
    int value;

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    new->data = value;
    new->next = NULL;

    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        tail->next = new;
        tail = new;
    }

    printf("Node inserted at end successfully.\n");
}

// 5. Insert at Specific Position (0-indexed)
void insertAtPos() {
    int value, pos, i;

    printf("Enter position (0-indexed): ");
    scanf("%d", &pos);

    if (pos == 0) {
        insertAtBeg();
        return;
    }

    temp = head;
    for (i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds!\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    new->data = value;
    new->next = temp->next;
    temp->next = new;

    if (new->next == NULL) {
        tail = new;
    }

    printf("Node inserted at position %d successfully.\n", pos);
}

// 6. Delete from Beginning
void deleteAtBeg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// 7. Delete from End
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head == tail) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    printf("Deleted element: %d\n", tail->data);
    free(tail);
    temp->next = NULL;
    tail = temp;
}

// 8. Delete from Specific Position (0-indexed)
void deleteAtPos() {
    int pos, i;
    struct node *delNode;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete (0-indexed): ");
    scanf("%d", &pos);

    if (pos == 0) {
        deleteAtBeg();
        return;
    }

    temp = head;
    for (i = 0; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds!\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail) {
        tail = temp;
    }

    printf("Deleted element: %d\n", delNode->data);
    free(delNode);
}

int main() {
    int choice;

    while (1) {
        printf("\n==================================");
        printf("\n    SINGLY LINKED LIST MENU       ");
        printf("\n==================================");
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Insert at Beginning");
        printf("\n4. Insert at End");
        printf("\n5. Insert at Position");
        printf("\n6. Delete from Beginning");
        printf("\n7. Delete from End");
        printf("\n8. Delete from Position");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertAtBeg(); break;
            case 4: insertAtEnd(); break;
            case 5: insertAtPos(); break;
            case 6: deleteAtBeg(); break;
            case 7: deleteAtEnd(); break;
            case 8: deleteAtPos(); break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Enter between 1 and 9.\n");
        }
    }

    return 0;
}
