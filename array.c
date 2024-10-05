#include<stdio.h>
int i,a[50],x,p,n,c,d,pos;
void insert(){
    printf("Enter position to add your number\n");
    scanf("%d",&pos);
    printf("Enter the element to be added\n");
    scanf("%d",&x);
    n++;
    for (i = n; i > pos; i--){
        a[i] = a[i-1];
    }
    a[pos] = x;
    if(pos<=0 || pos>n+1){
        printf("invalid position");
    } 
}
void delete(){
        int pos;
        printf("Enter position to be deleted:\n");
        scanf("%d",&pos);
        for(i=pos;i<n;i++){
                a[i]=a[i+1];
        }
        n--;
}
void search(){
    printf("Enter the element you want to search from the array\n");
    scanf("%d",&x);
    for (i=1; i<=n; i++)
    {
        if (x==a[i])
        p=i;
    }
    printf("%d element is at the %d postion in the array\n",x,p);
}
void display(){
    printf("The elements of array are:\n");
    for(i=1;i<=n;i++){
        printf("%d \n",a[i]);
    }
}
void max(){
    int max=a[0];
    for(i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    printf("Maximum number is %d\n",max);
}
int main(){
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(1){
        printf("Enter your choice: (1)INSERT, (2)DELETE, (3)DISPLAY, (4)SEARCH, (5)MAX\n");
        scanf("%d",&c);
        switch(c){
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: search();
            break;
            case 5: max();
            break;
            default: 
            return 0;
        }
    }
}