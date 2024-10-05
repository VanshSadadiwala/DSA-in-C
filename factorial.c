/*Implement following C programs using Recursion
• To calculate and print factorial of a given number*/
#include<stdio.h>
int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int main(){
    int num,f;
    printf("enter value of n =");
    scanf("%d",&num);
    f=factorial(num);
    printf("\n factorial = %d",f);
}