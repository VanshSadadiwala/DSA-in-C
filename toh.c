/*• To solve Tower of Hanoi Problem for given number of disks*/
#include<stdio.h>
void tower_of_honoi(int n, char a, char b, char c){
    if(n == 1){
        printf("Move disk from %c to %c\n",a,b);
    }
    else{        tower_of_honoi(n-1, a, c, b);
        printf("Move disk from %c to %c\n",a,b);
        tower_of_honoi(n-1, c, b, a);
    }
}
int main(){
    int n;
    printf("Enter how the number of disks: ");
    scanf("%d",&n);
    tower_of_honoi(n,'A', 'B', 'C');
}
