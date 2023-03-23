#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node *next;
} node;

node *start=NULL;

node *create_ll(node *start){
    node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d",&num);
    while(num != -1){
        new_node= (node*) malloc(sizeof(node));
        new_node->data = num;
        if(start==NULL){
            new_node->next= new_node;
            start= new_node;
        }
        else{
            ptr=start;
            while(ptr->next !=start){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next =start;
        }
        printf("\n Enter the data : ");
        scanf("%d",&num);
    }
    return start;
}

node *display(node *start){
    node *ptr= start;
    if(ptr==NULL)
        return;
    while(ptr->next !=start){
            printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t %d",ptr->data);
    return start;
}

node *insert_beg(node *start){
    node *new_node;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node = (node*) malloc(sizeof(node));
    new_node->data = num;
    node *ptr=start;
    if(start==NULL){
        new_node->next= new_node;
        start= new_node;
        return start;
    }
    while(ptr->next !=start){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next = start;
    start=new_node;
    return start;
}

node *insert_end(node *start){
    node *new_node,*ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    new_node= (node*) malloc(sizeof(node));
    new_node->data= num;
    ptr=start;
    if(start==NULL){
        new_node->next= new_node;
        start= new_node;
        return start;
    }
    while(ptr->next !=start){
        ptr=ptr->next;
    }
    ptr->next =new_node;
    new_node->next=start;
    return start;
}

node *delete_beg(node *start){
    node *ptr =start;
    while(ptr->next !=start)
        ptr=ptr->next;
    ptr->next =start->next;
    free(start);
    start=ptr->next; 
    return start;
}

node *delete_end(node *start){
    node *ptr,*preptr;
    ptr=start;
    while(ptr->next !=start){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

node *delete_after(node *start){
    node *ptr,*nextptr;
    int val;
    printf("Enter the value after which the node has to be deleted : ");
    scanf("%d",&val);
    ptr=start;
    nextptr=ptr->next;
    while(ptr->data != val){
        ptr=ptr->next;
        nextptr=ptr->next;
    }
    if(nextptr==start)
        start=nextptr->next;
    ptr->next = nextptr->next;
    free(nextptr);
    return start;
}

node *delete_list(node *start){
    node *ptr;
    ptr=start;
    if(ptr==NULL)
        return;
    while(ptr->next!=start){
        start=delete_end(start);
    }
    free(start);
    start=NULL;
    return start;
}

int main(int argc,char *argv[]){
   int option;
   do{
       printf("\n\n *****MAIN MENU*****");
       printf("\n 1. Create a list");
       printf("\n 2. Display the list");
       printf("\n 3. Add a node at the beginning");
       printf("\n 4. Add a node at the end");
       printf("\n 5. Delete a node from the beginning");
       printf("\n 6. Delete a node from the end");
       printf("\n 7.Delete a node after a given node");
       printf("\n 8.Delete the entire list");
       printf("\n 9.EXIT");
       printf("\n\nEnter your option : ");
       scanf("%d",&option);
       switch(option){
            case 1: 
                   start = create_ll(start);
                   printf("\n LINKED LIST CREATED");
                   break;
                
            case 2: 
                   start = display(start);
                   break;
                
            case 3: 
                   start = insert_beg(start);
                   break;
                
            case 4: 
                   start = insert_end(start);
                   break;
                
            case 5:
                   start = delete_beg(start);
                   break;
                
            case 6: 
                   start = delete_end(start);
                   break;
                
            case 7: 
                   start = delete_after(start);
                   break;
                
            case 8:
                   start = delete_list(start);
                   printf("\n LINKED LIST DELETED");
                   break;
       }
   }while(option !=9);
   return 0;
}
