//1. Introduction to pointers. Write a C program to swap two values using Call by Value and Call by reference.
#include<stdio.h>
int swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    
}
int swapr(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int a,b;
    printf("Enter the value of a : \n");
    scanf("%d",&a);
    printf("Enter the value of b : \n");
    scanf("%d",&b);
    swap(a,b);
    printf("Using call by value then : \n a= %d \n b= %d\n",a,b);
    swapr(&a,&b);
    printf("Using call by reference then : \n a= %d \n b= %d",a,b);
    return 0;
}