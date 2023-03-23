#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 3
struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

struct stack *push(struct stack *top,int val){
    struct stack *ptr;
    ptr= (struct stack*) malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL){
        ptr->next =NULL;
        top=ptr;
    }
    else{
        ptr->next = top;
        top=ptr;
    }
    return top;
}

struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
        printf("\n Stack underflow");
    else{
        top=top->next;
        printf("\n The value being deleted is: %d",ptr->data);
        free(ptr);
    }
    return top;
}

int peek(struct stack *top){
    if(top==NULL){
        return -1;
    }
    else
        return top->data;
}

struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr=top;
    if(ptr==NULL)
        printf("\n Stack is empty");
    else{
        while(ptr!=NULL){
            printf("\n %d",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
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
                top=push(top,val);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                val = peek(top);
                if(val != -1)
                    printf("\n The value stored at top of the stack is:%d",val);
                break;
            case 4:
                top=display(top);
                break;
        }
    }while(option != 5);
}
