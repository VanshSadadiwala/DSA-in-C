#include<stdio.h>
#define size 30
int j=0,top=-1;
char stack[size],x,infix[size],prefix[size],postfix[size],ch;

void push(char c){
    top++;
    stack[top]=c;
}

char pop(){
    x=stack[top];
    --top;
    return x;
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
        case '-':p=2;
                break;
        case '*':
        case '/':p=4;
                break;
        case '^':p=5;
                break;
    }
    return p;
}

int instack(char c){
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
        case ')':p=0;
                break;
        case '#':p=-1;
                break;
    }
    return p;
}
void main(){
    push('#');
    printf("Enter infix string:");
    scanf("%s",infix);
    int len=0;
    int k=0;
    //reversing infix and storing in postfix to convert
    while(infix[len]!='\0'){
        len++; //to claculate length of a string
    }
    for(int l=len-1;l>=0;l--){ 
        postfix[k]=infix[l]; //for reversing infix string and storing in postfix
        k++;
    }
    printf("%s",postfix);
    for(int i=0; postfix[i]!='\0'; i++){
        ch=postfix[i];
        if(ch>='a' && ch<='z'|| ch>='A' && ch<='Z'){
            prefix[j]=ch;
            j++;
        }
        else if(ch==')'){
            push(')');
        }
        else if(ch=='('){
            while((x=pop())!=')'){
                prefix[j]=x;
                j++;
            }
        }
        else{
            while(incoming(ch)<=instack(stack[top])){
                prefix[j]=pop();
                j++;
            }
            push(ch);
        }
    }
    while(!isempty()){
        prefix[j]=pop();
        j++;
    }
    prefix[j-1]='\0'; //for making postfix last second element #->/0(null terminate)
    len=0;
    //again for answer reversing prefix and storing in prefix only
    while(prefix[len]!='\0'){
        len++; //to calculate length of a string
    }
    char temp;
    for (int l = 0; l < len / 2; l++) { // Reversing prefix string
        temp = prefix[l];
        prefix[l] = prefix[len - l - 1];
        prefix[len - l - 1] = temp;
    }
    printf("Prefix String: %s",prefix);   
}