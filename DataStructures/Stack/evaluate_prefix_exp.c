#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define M 100

float st[M];
int top=-1;

void push(float st[],float val);
float pop(float st[]);
float evaluatePrefixExp(char exp[]);

int main(){
    float val;
    char exp[100];
    printf("\n Enter any Prefix expression : ");
    gets(exp);
    val=evaluatePrefixExp(exp);
    printf("\n Value of the Prefix expression = %.2f",val);
    return 0;
}

float evaluatePrefixExp(char exp[]){
    int i=strlen(exp)-1;
    float op1,op2,value;
    while(i>=0){
        if(isdigit(exp[i])){
            push(st,(float)(exp[i]-'0'));
        }
        else{
            op1=pop(st);
            op2=pop(st);
            switch(exp[i]){
                case '+':
                    value=op1+op2;
                    break;
                case '-':
                    value=op1-op2;
                    break;
                case '*':
                    value=op1*op2;
                    break;
                case '/':
                    value=op1/op2;
                    break;
                case '%':
                    value=(int)op1 % (int) op2;
                    break;
            }
            push(st,value);
        }
        i--;
    }
    return pop(st);
}

void push(float st[],float val){
    if(top==M-1){
        printf("\n Stack Overflow");
    }
    else{
        st[++top]=val;
    }
}

float pop(float st[]){
    float val;
    if(top==-1){
        printf("\n Stack Underflow");
    }
    else{
        val=st[top];
        top--;
    }
    return val;
}
