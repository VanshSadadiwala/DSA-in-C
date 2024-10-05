//8. Implement a program for ARRAY that performs following operations using function.
//(a) INSERT (b) DELETE (c) DISPLAY (d) SEARCH (e) MAX
#include<stdio.h>
int a[50],n,i;
void insert(){
        int pos,x;
        printf("Enter value to be inserted:\n");
        scanf("%d",&x);
        printf("Enter pos to insert value on:");
        scanf("%d",&pos);
        n++;
        for(i=n;i>pos;i--){
                a[i]=a[i-1];
        }
        a[pos]=x;
        if(pos<=0 || pos>n+1){
                printf("invalid position");
        }
}
void delete(){
        int pos;
        printf("Enter position number which is to be deleted:\n");
        scanf("%d",&pos);
        for(i=pos;i<n;i++){
                a[i]=a[i+1];
        }
        n--;
}
void display(){
        printf("Elements of array are:\n");
        for(i=0;i<=n;i++){
                printf("%d",a[i]);
        }
}
void search(){
        int x,count=0;
        printf("Search:\n");
        scanf("%d",&x);
        for(i=0;i<n;i++){
                if(a[i]==x){
                        count=1;
                }
        }
        if(count==1){
                printf("Search Found!");
        }
        else{
                printf("Search not found");
        }
}
void max(){
        int max=a[0];
        for(i=0;i<n;i++){
                if(max<a[i]){
                        max=a[i];
                }
        }
        printf("Maximum number is %d",max);
}
int main()
{
    int s;
    printf("Enter size of array: ");
    scanf("%d",&s);
    printf("Enter element of array: ");
    for(i=0;i<s;i++){
        scanf("%d",&a[i]);
    }
    while(1){
    printf("\n Choose:\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.SEARH\n5.MAX\n");
    printf("Choose the operation:\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:insert();
               break; 
        case 2:delete();
                break;
        case 3:display();
                break;
        case 4:search();
                break;
        case 5:max();
                break;
        default: printf("invalid input");
                return 0;
    }
    }

}