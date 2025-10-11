#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    void  *data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front, *rear;
    size_t data_size;
    size_t size;
} Queue;

void init_queue(Queue *q, size_t data_size){
  q->front = q->rear = NULL;
  q->data_size = data_size;
  q->size = 0;
}

Node* create_new_node(void *data, size_t data_size){
    size_t i;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;
    return new_node;
}

void push(Queue *q, void *data){
    Node *new_node = create_new_node(data, q->data_size);
    if(q->rear == NULL){
        q->front = q->rear = new_node;
        q->size++;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
    q->size++;
}

void pop(Queue *q){
    Node *temp;
    if(q->front == NULL) return;
    temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;
    free(temp->data);
    free(temp);
    q->size--;
}

void* front(Queue *q){
    return q->front->data;
}

void* rear(Queue *q){
    return q->rear->data;
}

int empty(Queue *q){
    return q->size == 0;
}

void clear(Queue *q){
    Node *temp;
    while(q->front != NULL){
        temp = q->front;
        q->front = q->front->next;
        free(temp->data);
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

int main(int argc,char *argv[]){
   int option,data;
   Queue q;
   do{
     printf("\n\n *****MAIN MENU*****");
     printf("\n 1. Create a Queue");
     printf("\n 2. Display front and rear");
     printf("\n 3. Push");
     printf("\n 4. Pop");
     printf("\n 5. Check if empty");
     printf("\n 6. Size of Queue");
     printf("\n 7. Delete Queue");
     printf("\n 8. EXIT");
     printf("\n\nEnter your option : ");
     scanf("%d",&option);
     switch(option){
        case 1: 
            init_queue(&q, sizeof(int));
            printf("Queue created\n");
            break;
            
        case 2: 
            if(!empty(&q)){
                printf("Front: %d\n", *(int*)front(&q));
                printf("Rear: %d\n", *(int*)rear(&q));
            } else {
                printf("Queue is empty\n");
            }
            break;
            
        case 3: 
            printf("Enter an integer to push: ");
            scanf("%d", &data);
            push(&q, &data);
            break;
            
        case 4: 
            if(!empty(&q)){
                printf("Popped: %d\n", *(int*)front(&q));
                pop(&q);
            } else {
                printf("Queue is empty\n");
            }
            break;
            
        case 5:
            if(empty(&q)){
                printf("Queue is empty\n");
            } else {
                printf("Queue is not empty\n");
            }
            break;
            
        case 6: 
            printf("Size of Queue: %ld\n", q.size);
            break;
            
        case 7: 
            clear(&q);
            printf("Queue deleted\n");
            break;
            
        case 8:
            clear(&q);
            printf("\n EXITING\n");
            break;
       
        default:
            printf("\n INVALID OPTION \n");
            break;
     }
   }while(option !=8);

   return 0;
}
