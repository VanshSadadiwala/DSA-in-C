#include<stdio.h>
int n,i;
struct student
{
    char name[50];
    int rollno;
    int m1,m2,m3;
};
void printdetails(struct student s[50],int n)
{
    for(i=1;i<=n;i++){
        printf("For student %d\n",i);
        printf("Name: %s\n",s[i].name);
        printf("roll number is %d\n",s[i].rollno);
        printf("Marks for sub1 is %d\n",s[i].m1);
        printf("Marks for sub2 is %d\n",s[i].m2);
        printf("Marks for sub3 is %d\n",s[i].m3);
    }  
}
int main()
{  
    struct student s[50];
    printf("Enter total number of student to add details: ");
    scanf("%d",&n);
    for ( i =1; i<=n; i++)
    {
        printf("For student %d\n",i);
        printf("Enter name:\n");
        scanf("%s",s[i].name);
        printf("Enter roll number:\n");
        scanf("%d",&s[i].rollno);
        printf("Enter Marks for sub1:\n");
        scanf("%d",&s[i].m1);
        printf("Enter Marks for sub2:\n");
        scanf("%d",&s[i].m2);
        printf("Enter Marks for sub3:\n");
        scanf("%d",&s[i].m3);   
    }
    printdetails(s,n);
}