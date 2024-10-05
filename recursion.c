#include<stdio.h>
int foo(int n){
    static int r=40;
    if(n==0 || n==1)
        return 0;
        if(n%2==0){
            r=r-4;
            return foo(n-1)-r;
        }
        else{
            return foo(n-1)+2*r;
        }
}
int main(){
    printf("%d",foo(6));
    return 0;
}