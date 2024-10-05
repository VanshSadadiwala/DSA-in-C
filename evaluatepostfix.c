/*2) Write a C program to perform postfix evaluation.*/
#include<stdio.h>
#include<math.h>
#define size 30
    char postfix[size];
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
    op2 = pop();
    op1 = pop();
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
    if (top != 0){
        printf("Error: Invalid expression\n");
        return 0;
    }
    else{
        printf("Answer is %d\n",pop());
    }
}
int main(){

    printf("Enter your postfix expression:\n");
    scanf("%s",postfix);
    int ch;
    for(int i=0; postfix[i] != '\0'; i++){
        ch = postfix[i];
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