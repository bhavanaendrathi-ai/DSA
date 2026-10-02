
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node *new, *temp, *top = NULL;
void push(int ele){
    new = (struct node *) malloc (sizeof (struct node));
    if(top == NULL){
        new -> data = ele;
        new -> next = NULL;
        top = new;
    }else{
        new -> data = ele;
        new -> next = top;
        top = new;
    }
}

void pop(){
    int ele;
    if(top == NULL)
    {
        printf("stack is empty!");
    }else
    {
        temp = top;
        ele = top -> data;
        printf("%d is the deleted element!",top -> data);
        top = top -> next;
        temp -> next = NULL;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("stack is empty!");
    }else{
        printf("%d is the top of stack",top -> data);
    }
}

void display(){
    if(top == NULL)
    {
        printf("stack is empty!");
    }else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
    }
}
int main() {
    int choice, ele;
    while(1){
        printf("\n=== stack operations ===\n");
        printf("\n 1.push \n 2.pop \n 3.display \n 4.peek \n 5.exit \n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter an element: ");
            scanf("%d",&ele);
            push(ele);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            printf("\n exiting...");
            exit(1);
            default:
            printf("invalid choice! please try again!");

        }

    }



    return 0;
}
