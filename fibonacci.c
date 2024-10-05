#include<stdio.h>
int fibonacci(int n){ // 0 1 1 2 3 5 8 13 21
    if (n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int choice, n;
    while(1){
        printf("Enter your choice\n 1)Start\n 2)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter number to get the Nth fibonacci number\n");
                scanf("%d",&n);
                printf("The %d th fibonacci number is: %d\n", n, fibonacci(n));
            break;
            case 2:
                return 0;
        }
    }
}
