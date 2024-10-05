/*3) Write a C program to perform prefix evaluation.*/
#include<stdio.h>
#include<math.h>
#define size 30
    char postfix[size],prefix[size];
    int stack[size];
    int i, x, result, op1, op2;
    int  top = -1;
void push(int a){
    if(top == size - 1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=a;
        //printf("%d",a);
    }
}
int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x = stack[top];
        top--;
    }
    return x;
}

void evaluate(char c){
    op1 = pop();
    op2 = pop();
    switch(c){
        case '+':
            result = op1 + op2;
        break;
        case '-':
            result = op1 - op2;
        break;
        case '*': 
            result = op1 * op2;
        break;
        case '/': 
            result = op1 / op2;
        break;
        case '^':
            result = (int) pow(op1,op2);
        break; 
        default: printf("Invalid Operator\n");
    }
    push(result);
}
int final_result(){
    if(top != 0){
        printf("Error: Invalid expression\n");
        return 0;
    }
    else{
        printf("Answer is %d\n",pop());
    }
}
int main(){

    printf("Enter your prefix expression:\n");
    scanf("%s",prefix);
    int len=0;
    int k=0;
    //reversing infix and storing in postfix to convert
    while(prefix[len]!='\0'){
        len++; //to claculate length of a string
    }
    for(int l=len-1;l>=0;l--){ 
        postfix[k]=prefix[l]; //for reversing infix string and storing in postfix
        k++;
    }
    //postfix[k+1]='\0';
    //printf("%s",postfix);
    for(int i=0; postfix[i] != '\0'; i++){
        int ch = postfix[i];
        if (ch >= '0' && ch <= '9'){
            push(ch - '0');   // 53 - 48 = 3 
        }
        else if(ch == '+'||ch == '-' ||ch == '*' || ch == '/'||ch == '^'){
            evaluate(ch);
        }
        else{
            printf("Invalid charcter is inputed\n");
            return 0;
        }       
}
    final_result();
    return 0;
}