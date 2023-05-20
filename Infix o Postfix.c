#include <stdio.h>
#include<string.h>
#define size 20
char stack[size],ch[size];
int top = -1,topch = -1;
void pushch(char x){
    ch[++topch] = x;
}
char popch(){
    char x = ch[topch--];
    return x;
}
void push(char x){
    stack[++top] = x;
}
char pop(){
    char x = stack[top--];
    return x;
}
int precedence(char x){
    if(x == '*' || x == '/')
    return 1;
    if(x == '+' || x == '-')
    return 0;
}
void infixtopostfix(char s[size]){
        for(int i=0;s[i]!='\0';i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
            if(precedence(ch[top])<precedence(s[i])){
                push(s[i+1]);
                push(s[i]);
                i++;
            }
            else if(topch == -1) pushch(s[i]);
            else if( precedence(ch[top]) == precedence(s[i]) ){
            push(popch());
            pushch(s[i]);
            }
        }
        else push(s[i]);
    }
    while(topch!=-1){
        push(popch());
    }
}
int main()
{
    char s[size];
    gets(s);
    infixtopostfix(s);
    for(int i=0;s[i]!='\0';i++)
    printf("%c",stack[i]);
    return 0;
}
