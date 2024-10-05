#include<stdio.h>
#define size 20
char postfix[size],infix[size],stack[size];
int i;
int j=0; //for traversing or storing in postfix
char ch,waste;
int top=-1;
void push(char c){
    top++;
    stack[top]=c;
}
char pop(){
    waste=stack[top];
    top--;
    return waste;
}
int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int incoming(char c){
    int p;
    switch(c){
        case '+':
        case '-':p=1;
                break;
        case '*':
        case '/':p=3;
                break;
        case '^':p=6;
                break;
        case '(':p=7;
                break;
    }
    return p;
}

int instack(char c){
    int p;
    switch(c){
        case '+':
        case '-':p=2;
                break;
        case '*':
        case '/':p=4;
                break;
        case '^':p=5;
                break;
        case '(':p=0;
                break;
        case '#':p=-1;
                break;
    }
    return p;
}
int main(){
    printf("Enter infix:");
    scanf("%s",infix);
    push('#');
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
            postfix[j]=ch;
            j++; //first store itself then jagya karey for next element
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            char x;
            while((x=pop())!='('){
                postfix[j]=x;
                j++;    //first store itself then jagya karey for next element
            }
        }
        else{ //ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'
            while(incoming(ch)<=instack(stack[top])){
                postfix[j]=pop();
                j++;
            }
            push(ch); //if incoming priority is greater then psuh in stack i.e /inc and +instack then push in stack
        }
    }
    while(!isempty()){
            postfix[j]=pop();
            j++;
        }

    postfix[j-1]='\0'; //for making postfix last second element #->/0(null)
    printf("%s",postfix);

}