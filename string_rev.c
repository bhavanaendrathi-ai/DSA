#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char str[MAX];
int top = -1;

void push(char c){
    str[++top] = c;
    //printf("pushed into the stack %c",c);
}
char pop(){
    if(top == -1){
        printf("stack is underflow!");
        return '\0';
    }
    else{
        return str[top--];
    }
}

int main(){
    int i;
    printf("enter a string: ");
    scanf("%s",str);

    int len = strlen(str);

    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }

    printf("reveresed string is: ");

    while(top != -1){
        printf("%c",pop());
    }printf("\n");
    return 0;
}
