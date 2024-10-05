#include<stdio.h>
int a[50],x,n,c;
int top=-1;
int push()
{
    printf("Enter the element you want to push: ");
    scanf("%d",&x);
    top++;
    a[top]=x;
}
int pop()
{
    x=a[top];
    top--;
    printf("Your top element has been poped\n");
}
int peep()
{
    printf("The top element is: %d\n",a[top]);
}
int change()
{
    printf("Enter the element to change: \n");
    scanf("%d",&x);
    a[top]=x;
}
int display()
{
    int i;
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
    printf("Your elements are: \n");
    for( i=0;i<=top;i++)
    {
     printf("%d\n",a[i]);
    }
}
    }
int main()
{    
    while(1)
    {
        printf("Choose: \n(1) PUSH \n(2) POP \n(3) PEEP \n(4) CHANGE \n(5) DISPLAY\n Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: peep();
                break;
        case 4: change();
                break;
        case 5: display();
                break;
        default:return 0;
        }
    }
}
