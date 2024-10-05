#include<stdio.h>
#define size 10
int cqueue[size],front=-1,rear=-1;
void insert(int data){
    if(front==(rear+1)%size){
        printf("Circular Queue is Overflow\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        cqueue[rear]=data;
    }
}
void delete(){
    if(front==-1){
        printf("Queue is Underflow\n");
    }
    else{
        int data=cqueue[front];
        if(front == rear){
            front = rear= -1;
        }
        else{
            front=(front+1)%size;
        }
        printf("Deleted %d\n",data);
    }
}
void display(){
    if(front==-1){
        printf("\nCircular Queue is Underflow");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d ",cqueue[i]);
            i=(i+1)%size;
        }
        printf("%d",cqueue[i]); //to print last element i.e. equal to rear
        printf("\n");
    }
    
}
int main(){
    int c,num;
    while(1){
    printf("Choose: \n(1) INSERT \n(2) DELETE \n(3) DISPLAY\n Enter your choice:");
    scanf("%d",&c);
    switch(c){
        case 1: printf("Enter number to insert in cqueue:");
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