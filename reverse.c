#include<stdio.h>
void reverse(char str[]){
    if(str[0] == '\0'){
        return;
    }
    reverse(str + 1); // Storing characters in stack until reaching the base condition 
    
    printf("%c",str[0]);// So to print for hello stack is |o|l|l|e|h| str[0] means first character in first recursion and so on
}
int main(){
    char s[50];
    printf("Enter your string: ");
    fgets(s,sizeof(s),stdin);
    for(int i = 0; i < sizeof(s); i++){
        if(s[i] == '\n'){
            s[i] = '\0';
            break;
        }
    }
    printf("The reversed string is: ");
    reverse(s);
    return 0;
}
