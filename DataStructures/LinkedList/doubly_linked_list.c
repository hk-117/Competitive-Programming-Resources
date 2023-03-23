#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start=NULL;

struct node *create_ll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d",&num);
    while(num != -1){
        new_node= (struct node*) malloc(sizeof(struct node));
        new_node->data = num;
        if(start==NULL){
            new_node->prev= NULL;
            new_node->next= NULL;
            start= new_node;
        }
        else{
            ptr=start;
            while(ptr->next !=NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev=ptr;
            new_node->next =NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr= start;
    while(ptr!=NULL){
            printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    new_node->prev = NULL;
    start->prev = new_node;
    start=new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    new_node= (struct node*) malloc(sizeof(struct node));
    new_node->data= num;
    new_node->next=NULL;
    ptr=start;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    new_node->prev =ptr;
    ptr->next =new_node;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *new_node, *ptr;
    int num,val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value before which the data to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data !=val){
        ptr=ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return start;
}

struct node *insert_after(struct node *start){
    struct node *new_node, *ptr;
    int num,val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value after which the data to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data !=val){
        ptr=ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr =start;
    start= start->next;
    if(start!=NULL)
        start->prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start){
    struct node *ptr,*nextptr;
    int val;
    printf("Enter the value after which the node has to be deleted : ");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data != val){
        ptr=ptr->next;
    }
    nextptr = ptr->next;
    ptr->next = nextptr->next;
    nextptr->next->prev = ptr;
    free(nextptr);
    return start;
}

struct node *delete_before(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("Enter the value before which the node has to be deleted : ");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data != val){
        ptr=ptr->next;
    }
    preptr= ptr->prev;
    if(preptr==start)
        start=delete_beg(start);
    else{
        ptr->prev = preptr->prev;
        preptr->prev->next = ptr;
    }
    free(preptr);
    return start;
}

struct node *delete_list(struct node *start){
    struct node *ptr;
    if(start!=NULL){
        ptr=start;
        while(ptr!=NULL){
            printf("\n %d is to be deleted next",ptr->data);
            start=delete_beg(ptr);
            ptr=start;
        }
    }
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
       printf("\n 5. Add a node before a given node");
       printf("\n 6. Add a node after a given node");
       printf("\n 7. Delete a node from the beginning");
       printf("\n 8. Delete a node from the end");
       printf("\n 9. Delete a node before a given node");
       printf("\n 10.Delete a node after a given node");
       printf("\n 11.Delete the entire list");
       printf("\n 12.EXIT");
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
                   start = insert_before(start);
                   break;
                
            case 6: 
                   start = insert_after(start);
                   break;
                
            case 7: 
                   start = delete_beg(start);
                   break;
                
            case 8:
                   start = delete_end(start);
                   break;
                
            case 9: 
                   start = delete_before(start);
                   break;
                
            case 10: 
                    start = delete_after(start);
                    break;
            case 11: 
                    start = delete_list(start);
                    printf("\n LINKED LIST DELETED");
                    break;
       }
   }while(option !=12);
   return 0;
}
