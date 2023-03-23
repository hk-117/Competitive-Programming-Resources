#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct queue{
    node *front;
    node *rear;
};

void create_queue(queue *);
queue *insert(queue *,int);
queue *delete_element(queue *);
queue *display(queue *);
int peek(queue *);

int main(){
    int val,option;
    queue *q;
    create_queue(q);
    do{
        cout<<"\n ***** Main Menu ***** ";
        cout<<"\n 1.Insert";
        cout<<"\n 2.Delete";
        cout<<"\n 3.Peek";
        cout<<"\n 4.Display";
        cout<<"\n 5.Exit";
        cout<<"\n Enter your option : ";
        cin>>option;
        switch(option){
            case 1:
                cout<<"\nEnter the number to insert in the queue: ";
                cin>>val;
                q=insert(q,val);
                break;
            case 2:
                q=delete_element(q);
                break;
            case 3:
                val=peek(q);
                if(val!=-1)
                    cout<<"\n The value at front of the queue is : "<<val;
                break;
            case 4:
                q=display(q);
                break;
        }
    }while(option != 5);
    return 0;
}

void create_queue(queue *q){
    q->rear=NULL;
    q->front=NULL;
}

queue *insert(queue *q, int val){
    node *ptr;
    ptr= new node;
    ptr->data=val;
    if(q->front==NULL){
        q->front=ptr;
        q->rear=ptr;
        q->front->next=q->rear->next=NULL;
    }
    else{
        q->rear->next = ptr;
        q->rear=ptr;
        q->rear->next=NULL;
    }
    return q;
}

queue *display(queue *q){
    node *ptr;
    ptr= q->front;
    if(ptr==NULL)
        cout<<"\n Queue is empty";
    else{
        cout<<endl;
        while(ptr!=q->rear){
            cout<< ptr->data <<"\t";
            ptr=ptr->next;
        }
        cout<< ptr->data <<"\t";
    }
    return q;
}

queue *delete_element(queue *q){
    node *ptr;
    ptr=q->front;
    if(ptr==NULL)
        cout<<"\n Underflow";
    else{
        q->front=q->front->next;
        cout<<"\n The value being deleted is : "<<ptr->data;
        delete ptr;
    }
    return q;
}

int peek(queue *q){
    if(q->front ==NULL){
        cout<<"\n Queue is empty";
        return -1;
    }
    else
        return q->front->data;
}
