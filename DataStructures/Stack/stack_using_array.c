#include<stdio.h>
#include<stdlib.h>

#define MAX 3
int st[MAX],top =-1;

void push(int st[],int val){
    if(top ==MAX-1){
        printf("\n Stack overflow");
    }
    else{
        st[++top]=val;
    }
}

int pop(int st[]){
    if(top == -1){
        printf("\n Stack underflow");
        return -1;
    }
    else{
        int val= st[top];
        top--;
        return val;
    }
}

int peek(int st[]){
    if(top==-1){
        printf("\n Stack is empty");
        return -1;
    }
    else
        return st[top];
}

void display(int st[]){
    if(top == -1)
        printf("\n Stack is empty");
    else{
        for(int i=top;i>=0;i--){
            printf("\n %d",st[i]);
        }
        printf("\n");
    }
}

int main(){
    int val,option;
    do{
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. TOP");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                val =pop(st);
                if(val != -1)
                    printf("\n The value deleted from the stack is: %d",val);
                break;
            case 3:
                val = peek(st);
                if(val != -1)
                    printf("\n The value stored at top of the stack is:%d",val);
                break;
            case 4:
                display(st);
                break;
        }
    }while(option != 5);
}
