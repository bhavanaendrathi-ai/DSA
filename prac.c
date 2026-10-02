/*#include <stdio.h>

int main(){
    int i, count = 0;
    int arr[] = {7,12,5,8,14,9,20};

    for(i = 0; i <= arr[i]; i++){
        if(arr[i] % 2 == 0){
            count++;
        }
    }
    printf("even numbers: %d",count);
}
*/

/*#include <stdio.h>

int main(){
    int sum = 0;
    int count = 0;
    int i,j,avg = 0;
    int arr[] = {4,8,12,6,10};

    for(i = 0;i <= arr[i]; i++){
        sum = sum + arr[i];
        count++;
    }

    avg = sum/count;

    for(j = 0; j <= arr[i]; j++){
        if(arr[i]>avg){
            printf("%d",j);
        }
    }
}
*/

#include <stdio.h>

int main(){
    int i;

    for(i = 20; i < 80; i++)
    {
        if(i % 5 == 0 && i % 10 != 0){
            printf("%d\t",i);
        }
    }
}
































