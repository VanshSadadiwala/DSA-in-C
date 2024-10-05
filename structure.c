#include<stdio.h>
struct Student{
    char name[10];
    int rollno;
    int m1,m2,m3;
};
void result(struct Student s[50],int n){
    for(int i=0;i<n;i++){
    if(s[i].m1>=23 && s[i].m2>=23 && s[i].m3>=23){
        printf("\n%s is PASS",s[i].name);
    }
    else{
        printf("\n%s is FAIL",s[i].name);
    }
    }
}
void result_rollno(struct Student s[50],int n,int x) {
        for(int i=0;i<n;i++){
            if(s[i].rollno==x){
        printf("\nthe name of student %d is: %s",i+1,s[i].name);
        printf("\n the roll no. of student %d is: %d ",i+1,s[i].rollno);
        printf("\nTOTAL MARKS IS 70");
        printf("\n the marks of student %d of subject 1 is: %d",i+1,s[i].m1);
        printf("\n the marks of student %d of subject 2 is: %d",i+1,s[i].m2);
        printf("\n the marks of student %d of subject 3 is: %d",i+1,s[i].m3);
    }
    else{
    printf("\n student not found");
    }
        }
}
void result_name(struct Student s[50],int n,char y[]){
    for(int i=0;i<n;i++){
            if(s[i].name==y){
        printf("\nthe name of student %d is: %s",i+1,s[i].name);
        printf("\n the roll no. of student %d is: %d ",i+1,s[i].rollno);
        printf("\nTOTAL MARKS IS 70");
        printf("\n the marks of student %d of subject 1 is: %d",i+1,s[i].m1);
        printf("\n the marks of student %d of subject 2 is: %d",i+1,s[i].m2);
        printf("\n the marks of student %d of subject 3 is: %d",i+1,s[i].m3);
    }
    else{
    printf("\n student not found");
    }
    }
}
void display(struct Student s[50],int n){
    for(int i=0;i<n;i++){
        printf("\nthe name of student %d is: %s",i+1,s[i].name);
        printf("\nTOTAL MARKS IS 70");
        printf("\n the marks of student %d of subject 1 is: %d",i+1,s[i].m1);
        printf("\n the marks of student %d of subject 2 is: %d",i+1,s[i].m2);
        printf("\n the marks of student %d of subject 3 is: %d",i+1,s[i].m3);
    }
}
void high_per(struct Student s[50],int n){
    float pr[20];
    for(int i=0;i<n;i++){
        pr[i]=(s[i].m1+s[i].m2+s[i].m3)/70;
    }
    int max=pr[0];
    for(int j=0;j<n;j++){
        if(pr[j]>max){
            max=pr[j];
        }
    }
    for(int k=0;k<n;k++){
        if(pr[k]==max){
        printf("\nthe Highest percentage student is:");
        printf("\nthe name of student  is: %s",s[k].name);
        printf("\nTOTAL MARKS IS 70");
        printf("\n the marks of student  of subject 1 is: %d",s[k].m1);
        printf("\n the marks of student  of subject 2 is: %d",s[k].m2);
        printf("\n the marks of student  of subject 3 is: %d",s[k].m3);
        printf("\n the percentage of student  of is: %f",k+max);
        }
    }
}
int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct Student s[50];
    //to enter marks
    for(int i=0;i<n;i++){
        printf("Enter the name of student %d :",i+1);
        scanf("%s",s[i].name);
        printf("Enter the roll no. of student %d :",i+1);
        scanf("%d",&s[i].rollno);
        printf("TOTAL MARKS IS 70");
        printf("\nEnter the marks of student %d of subject 1:",i+1);
        scanf("%d",&s[i].m1);
        printf("Enter the marks of student %d of subject 2:",i+1);
        scanf("%d",&s[i].m2);
        printf("Enter the marks of student %d of subject 3:",i+1);
        scanf("%d",&s[i].m3);
        
    }
    display(s,n);
    result(s,n);
    //call by rollno
    printf("\nEnter roll no of student whose result you want:");
    int x;
    scanf("%d",&x);
    result_rollno(s,n,x);
    //call by name
    printf("\nEnter name of student whose result you want:");
    char y[10];
    scanf("%s",y);
    result_rollno(s,n,x);
    //percent
    high_per(s,n);
}