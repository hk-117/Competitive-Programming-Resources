#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    void  *data;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node *head;
    size_t data_size;
    size_t size;
} LinkedList;

void init_list(LinkedList *list, size_t data_size){
    list->head = NULL;
    list->data_size = data_size;
    list->size = 0;
}

Node* create_new_node(void *data, size_t data_size){
    size_t i;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;
    return new_node;
}

void insert_beg(LinkedList *list, void *data){
    size_t i;
    Node *new_node = create_new_node(data, list->data_size);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert_end(LinkedList *list, void *data){
    size_t i;
    Node *new_node = create_new_node(data, list->data_size);
    if(list->head == NULL){
        list->head = new_node;
    } else {
        Node *ptr = list->head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    list->size++;
}

void delete_beg(LinkedList *list){
    Node *ptr;
    if(list->head == NULL) return;
    ptr = list->head;
    list->head = list->head->next;
    free(ptr->data);
    free(ptr);
    list->size--;
}

void delete_end(LinkedList *list){
    Node *ptr, *prev;
    if(list->head == NULL) return;
    ptr = list->head;
    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr->data);
    free(ptr);
    list->size--;
}

void display_integer_list(LinkedList *list){
    Node *ptr = list->head;
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }
    while(ptr != NULL){
        printf("%d -> ", *(int*)(ptr->data));
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList *list){
    Node *ptr = list->head;
    Node *temp;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp->data);
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

int main(int argc,char *argv[]){
   int option,data;
   LinkedList list;
   do{
       printf("\n\n *****MAIN MENU*****");
       printf("\n 1. Create a list");
       printf("\n 2. Display the list");
       printf("\n 3. Add a node at the beginning");
       printf("\n 4. Add a node at the end");
       printf("\n 5. Delete a node from the beginning");
       printf("\n 6. Delete a node from the end");
       printf("\n 7. Delete the entire list");
       printf("\n 8. EXIT");
       printf("\n\nEnter your option : ");
       scanf("%d",&option);
       switch(option){
            case 1: 
               init_list(&list, sizeof(int));
               printf("\n LINKED LIST CREATED");
               break;
                
            case 2: 
               display_integer_list(&list);
               break;
                
            case 3: 
               printf("Enter an integer to insert at the beginning: ");
               scanf("%d", &data);
               insert_beg(&list, &data);
               break;
                
            case 4: 
                printf("Enter an integer to insert at the end: ");
                scanf("%d", &data);
                insert_end(&list, &data);
               break;
                
            case 5:
               delete_beg(&list);
               break;
                
            case 6: 
               delete_end(&list);
               break;
                
            case 7: 
               free_list(&list);
               break;
                
            case 8:
               free_list(&list);
               printf("\n EXITING\n");
               break;
           
            default:
               printf("\n INVALID OPTION \n");
               break;
       }
   }while(option !=8);

   return 0;
}
