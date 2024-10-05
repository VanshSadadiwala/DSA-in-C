#include<stdio.h>
#define size 10
int queue[size], front = -1, rear = -1;
void insert(int num){
    if(rear ==size -1){
        printf("Queue is Overflow");
    }
    else{
        rear=rear+1;
        queue[rear]=num;
        if(front == -1){
            front = 0;
        }
    }
}
void delete(){
    if(front == -1 || front>rear){
        printf("Queue is Underflow");
    }
    else{
        int x=queue[front];
        front++;
    }
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main(){
    int c,num;
    while(1){
    printf("Choose: \n(1) INSERT \n(2) DELETE \n(3) DISPLAY\n Enter your choice:");
    scanf("%d",&c);
    switch(c){
        case 1: printf("Enter number to insert in queue:");
                scanf("%d",&num);
                insert(num);
        break;
        case 2: delete();
        break;
        case 3: display();
        break;
        default:printf("Invalid Input");
                return 0;
        }
    }
}
