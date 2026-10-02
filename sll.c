#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node *NODE;

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
    temp->link = first;

    return temp;
}

NODE insert_rear(int ele, NODE first) {
    NODE temp, cur;

    temp = getnode();
    temp->data = ele;
    temp->link = NULL;

    if (first == NULL)
        return temp;

    cur = first;

    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;

    return first;
}

NODE insert_pos(int ele, int pos, NODE first) {
    int c = 1;
    NODE temp, cur = first, prev = NULL;

    if (pos == 1)
        return insert_front(ele, first);

    temp = getnode();
    temp->data = ele;

    while (cur != NULL) {
        if (c == pos) {
            prev->link = temp;
            temp->link = cur;
            return first;
        }

        prev = cur;
        cur = cur->link;
        c++;
    }

    printf("Position is invalid!\n");
    free(temp);

    return first;
}

NODE delete_front(NODE first) {
    NODE cur;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    cur = first;
    first = first->link;

    printf("Element deleted is %d\n", cur->data);

    free(cur);

    return first;
}

NODE delete_position(int pos, NODE first) {
    int c = 1;
    NODE cur = first, prev = NULL;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    if (pos == 1)
        return delete_front(first);

    while (cur != NULL) {
        if (c == pos) {
            prev->link = cur->link;

            printf("Element deleted is %d\n", cur->data);

            free(cur);

            return first;
        }

        prev = cur;
        cur = cur->link;
        c++;
    }

    printf("Position is invalid!\n");

    return first;
}

NODE delete_rear(NODE first) {
    NODE cur, prev;

    if (first == NULL) {
        printf("List is empty!\n");
        return first;
    }

    if (first->link == NULL) {
        printf("Element deleted is %d\n", first->data);
        free(first);
        return NULL;
    }

    cur = first;

    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }

    prev->link = NULL;

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
        printf("%d -> ", cur->data);
        cur = cur->link;
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