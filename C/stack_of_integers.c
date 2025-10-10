#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    void  *data;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *head;
    size_t data_size;
} Stack;

void init_stack(Stack *stack, size_t data_size){
    stack->head = NULL;
    stack->data_size = data_size;
}

Node* create_new_node(void *data, size_t data_size){
    size_t i;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;
    return new_node;
}

void push(Stack *stack, void *data){
    size_t i;
    Node *new_node = create_new_node(data, stack->data_size);
    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(Stack *stack){
    Node *ptr;
    if(stack->head == NULL) return;
    ptr = stack->head;
    stack->head = stack->head->next;
    free(ptr->data);
    free(ptr);
}

Node* top(Stack *stack){
  return stack->head;
}

void clear(Stack *stack){
    Node *ptr = stack->head;
    Node *temp;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp->data);
        free(temp);
    }
    stack->head = NULL;
}

int main(int argc,char *argv[]){
   int option,data;
   Stack stack;
   Node *tmp;
   do{
     printf("\n\n *****MAIN MENU*****");
     printf("\n 1. Create a stack");
     printf("\n 2. Push");
     printf("\n 3. Pop");
     printf("\n 4. Top");
     printf("\n 5. Clear");
     printf("\n 6. EXIT");
     printf("\n\nEnter your option : ");
     scanf("%d",&option);
     switch(option){
        case 1: 
           init_stack(&stack, sizeof(int));
           printf("\n Stack Created.\n");
           break;
            
        case 2: 
           printf("Enter an integer to insert at the top: ");
           scanf("%d", &data);
           push(&stack, &data);
           break;
            
        case 3: 
           pop(&stack);
           break;
            
        case 4: 
           tmp =  top(&stack);
           if(tmp == NULL){
             puts("\nEmpty Stack\n");
           }else{
             printf("\nTop = %d\n",*(int*)tmp->data);
           }
           break;
            
        case 5:
           clear(&stack);
           break;
            
        case 6:
           clear(&stack);
           printf("\n EXITING\n");
           break;
       
        default:
           printf("\n INVALID OPTION\n");
           break;
     }
   }while(option !=6);

   return 0;
}
