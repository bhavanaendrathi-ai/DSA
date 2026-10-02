#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node *NODE;

//create a new node and allocate the memory for it 
NODE getnode() {
    NODE X;
    X = (NODE)malloc(sizeof(struct node));

    if (X == NULL) {
        printf("No memory allocated\n");
        exit(1);
    }

    return X;
}

NODE insert_front(int ele, NODE first) {
    NODE temp;

    temp = getnode();
    temp->data = ele;
    temp->prev = NULL;
    temp->next = first;

    if (first != NULL)
        first->prev = temp;

    return temp;
}

NODE insert_rear(int ele, NODE first) {
    NODE temp, cur;

    temp = getnode();
    temp->data = ele;
    temp->next = NULL;

    if (first == NULL) {
        temp->prev = NULL;
        return temp;
    }

    cur = first;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    temp->prev = cur;

    return first;
}

NODE insert_pos(int ele, int pos, NODE first) {
    int c = 1;
    NODE temp, cur = first;

    if (pos == 1)
        return insert_front(ele, first);

    temp = getnode();
    temp->data = ele;

    while (cur != NULL && c < pos) {
        cur = cur->next;
        c++;
    }

    if (cur == NULL) {
        printf("Position is invalid!\n");
        free(temp);
        return first;
    }

    temp->prev = cur->prev;
    temp->next = cur;

    cur->prev->next = temp;
    cur->prev = temp;

    return first;
}

NODE delete_front(NODE first) {
    NODE temp;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    temp = first;
    first = first->next;

    if (first != NULL)
        first->prev = NULL;

    printf("Element deleted is %d\n", temp->data);

    free(temp);

    return first;
}

NODE delete_rear(NODE first) {
    NODE cur;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    cur = first;

    while (cur->next != NULL)
        cur = cur->next;

    if (cur->prev != NULL)
        cur->prev->next = NULL;
    else
        first = NULL;

    printf("Element deleted is %d\n", cur->data);

    free(cur);

    return first;
}

NODE delete_position(int pos, NODE first) {
    int c = 1;
    NODE cur = first;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    if (pos == 1)
        return delete_front(first);

    while (cur != NULL && c < pos) {
        cur = cur->next;
        c++;
    }

    if (cur == NULL) {
        printf("Position is invalid!\n");
        return first;
    }

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    cur->prev->next = cur->next;

    printf("Element deleted is %d\n", cur->data);

    free(cur);

    return first;
}

void display(NODE first) {
    NODE cur = first;

    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (cur != NULL) {
        printf("%d <=> ", cur->data);
        cur = cur->next;
    }

    printf("NULL\n");
}

int main() {
    int data, choice, T = 1, pos;
    NODE first = NULL;

    while (T) {

        printf("\n1. Insert front");
        printf("\n2. Insert rear");
        printf("\n3. Insert position");
        printf("\n4. Display");
        printf("\n5. Delete position");
        printf("\n6. Delete rear");
        printf("\n7. Delete front");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            first = insert_front(data, first);
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &data);
            first = insert_rear(data, first);
            break;

        case 3:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            first = insert_pos(data, pos, first);
            break;

        case 4:
            display(first);
            break;

        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            first = delete_position(pos, first);
            break;

        case 6:
            first = delete_rear(first);
            break;

        case 7:
            first = delete_front(first);
            break;

        case 8:
            printf("exiting...");
            T = 0;
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}