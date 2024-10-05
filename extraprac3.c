#include <stdio.h>
#include <string.h>
struct student{
    int m1, m2, m3, roll;
    float per;
    char name [50];
}s[50];

void display(struct student s){
printf("The name of Student is: %s\n",s.name);
printf(" The Roll Number of Student is: %d\n",s.roll);
printf(" The total marks are out of 70\n");
printf(" The Marks of Subject m1 of Student is: %d\n",s.m1);
printf(" The Marks of Subject m2 of Student is: %d\n",s.m2);
printf(" The Marks of Subject m3 of Student is: %d\n",s.m3);
printf("The Percentage of student is %.2f\n",s.per);
}

void result(struct student s[50],int N){
    for(int i = 1; i <= N; i++){
        if(s[i].m1 >= 23 && s[i].m2 >= 23 && s[i].m3 >= 23){
            printf("%s has Passed\n",s[i].name);
        }
        else {
            printf("%s has failed\n",s[i].name);
        }
}
}

void result_rollno(struct student s[50],int x,int N){
    for(int i = 1; i <= N; i++){
        if (s[i].roll == x){
        printf("The name of Student %d is: %s\n",i,s[i].name);
        printf(" The Roll Number of Student %d is: %d\n",i,s[i].roll);
        printf(" The Marks of Subject m1 of Student %d is: %d\n",i,s[i].m1);
        printf(" The Marks of Subject m2 of Student %d is: %d\n",i,s[i].m2);
        printf(" The Marks of Subject m3 of Student %d is: %d\n",i,s[i].m3);
        printf("The Percentage of student is %.2f\n",s[i].per);
        break;
        }
        else{
            printf("No student found with roll number %d\n",x);
        }
    }
}

void result_name(struct student s[50],char y[],int N){
    for(int i = 1; i <= N; i++){
        if (strcmp(s[i].name,y) == 0){
            display(s[i]);
            return;
        }  
    }
    printf("No student found with name %s\n",y);
}
void high_per(struct student s[50],int max,int N){
        for(int i = 1; i <= N; i++){
        if(s[i].per==max){
        printf("The name of Student is: %s\n",s[i].name);
        printf(" The Roll Number of Student is: %d\n",s[i].roll);
        printf(" The Marks of Subject m1 of Student is: %d\n",s[i].m1);
        printf(" The Marks of Subject m2 of Student is: %d\n",s[i].m2);
        printf(" The Marks of Subject m3 of Student is: %d\n",s[i].m3);
        printf("The Percentage of student is %.2f\n",s[i].per);
        }
        }
}

int main(){
    int N,x;
    printf("Enter the total number of students to fill in the entries\n");
    scanf("%d",&N);
    
    for(int i = 1; i <= N; i++){
        printf("Enter the name of Student %d: ",i);
        scanf("%s",s[i].name);
        printf("Enter the Roll Number of Student %d: ",i);
        scanf("%d",&s[i].roll);
        printf("Enter the Marks of Subject m1 of Student %d: ",i);
        scanf("%d",&s[i].m1);
        printf("Enter the Marks of Subject m2 of Student %d: ",i);
        scanf("%d",&s[i].m2);
        printf("Enter the Marks of Subject m3 of Student %d: ",i);
        scanf("%d",&s[i].m3);
        s[i].per = ((s[i].m1 + s[i].m2 + s[i].m3) * 100) /210;
        printf("The Percentage of student %d is %.2f\n",i,s[i].per);
    }
    result(s,N);
    printf("Enter the Student Roll number to check their result \n");
    scanf("%d",&x);
    result_rollno(s,x,N);
    char y[50];
    printf("Enter the name of the student to get their result \n");
    scanf("%s",y);
    result_name(s,y,N);
    printf("The student with highest percentage: \n");
    int max = s[0].per;
    for (int i = 1; i <= N; i++){
        if (s[i].per > max){
            max = s[i].per;
        }
    }
    high_per(s,max,N);
}