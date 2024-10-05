#include<stdio.h>
int multiplication(int a, int b){
    int result;
    if(a == 0 || b == 0)
        return 0;
    else{
        result = a + multiplication(a, b - 1);
        return result;
    }
}

int main(){
int a,b;
printf("Enter first number: ");
scanf("%d",&a);
printf("Enter second number: ");
scanf("%d",&b);
printf("The multiplication of %d and %d is %d",a,b,multiplication(a,b));
}
