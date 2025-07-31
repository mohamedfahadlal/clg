#include  <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c){
    if(top >= 99){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}

int isp(char c){
    if(c == '+' || c == '-'){
        return 2;
    }
    else if(c == '*' || c == '/'){
        return 4;
    }
    else if(c == '^'){
        return 5;
    }
    else if(c == '('){
        return 0;
    }
    return -1;
}

int icp(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 3;
    }
    else if(c == '^'){
        return 6;
    }
    else if(c == '('){
        return 9;
    }
    else if(c == ')'){
        return 0;
    }
    return -1;
}

int main(){
    char exp[100];
    printf("Enter the expression:");
    scanf("%s",exp);

    strcat(exp, ")");
    push('(');
    int len = strlen(exp);
    int i =0;

    
    while(top>=0 && i<len) {
        
        char item = exp[i];
        char x = pop();
        if(isalpha(item)){
            push(x);
            printf("%c",item);
        } 
        else if(item == ')'){
            while(x!='('){
                printf("%c",x);
                x = pop();
            }
        }
        else if(isp(x) >= icp(item)){
            while(isp(x) >= icp(item)){
                printf("%c",x);
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(isp(x)<icp(item)){
            push(x);
            push(item);
        }
        else{
            printf("Invalid expression\n");
        }
        i++;
    }
       
    
    
    return 0;
}