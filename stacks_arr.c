// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1;
int stack[SIZE];
int i,ele;

//push operator
void push(int ele)
{
    if(top == SIZE - 1){
        printf("stack is overflow!");
    }else{
        top++;
        stack[top] = ele;
        printf("%d is pushed into the stack\n",ele);
    }
}

void pop(){
    if(top == -1){
        printf("stack is underflow!");
    }else{
        printf("%d element is deleted from the stack",stack[top]);
        top = top - 1;
    }
}

void peek(){
    if (top == -1){
        printf("stack is underflow!");
    }else{
        printf("top of the stack is %d",stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("stack is underflow!");
    }
    else{
        for(i = top; i >= 0 ; i++)
        {
            printf("%d",stack[i]);
        }
    }
}
int main() {
    // Write C code here
    int ele,choice;

    while(1)
    {
        printf("stack operations");
        printf("\n 1.push\n 2.pop \n 3.peek \n 4.display \n 5.exit \n");
        printf("enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
            {
                case 1: 
                    printf("enter your element: ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    peek();
                    break;
                case 4:display();
                    break;
                case 5:
                    printf("exiting...");
                    exit(0);
                default:
                printf("invalid choice! please try again...");
                
            }
    }

    return 0;
}