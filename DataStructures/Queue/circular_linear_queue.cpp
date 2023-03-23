#include<iostream>
#define MAX 10
using namespace std;

int queue[MAX];
int front= -1,rear= -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main(){
    int option,val;
    do{
        cout<<"\n\n ***** MAIN MENU ***** ";
        cout<<"\n 1.Insert an element";
        cout<<"\n 2.Delete an element";
        cout<<"\n 3.Peek";
        cout<<"\n 4.Display the queue";
        cout<<"\n 5.Exit";
        cout<<"\n Enter your option : ";
        cin>>option;
        switch(option){
            case 1:
                insert();
                break;
            case 2:
                val=delete_element();
                if(val != -1)
                    cout<<"\n The number deleted is : "<<val;
                break;
            case 3:
                val=peek();
                if(val != -1)
                    cout<<"\n The first value in queue is : "<<val;
                break;
            case 4:
                display();
                break;
        }
    }while(option != 5);
    return 0;
}

void insert(){
    int num;
    cout<<"\n Enter the number to be inserted in the queue : ";
    cin>>num;
    if(front==0 && rear==MAX-1){
        cout<<"\n Overflow";
        return;
    }
    else if(front== -1 && rear== -1)
        front=rear=0;
    else if(rear=MAX-1 && front!=0){
        rear=0;
    }
    else
        rear++;
    queue[rear]=num;
}

int delete_element(){
    int val;
    if(front== -1 && rear==-1){
        cout<<"\n Underflow";
        return -1;
    }
    val=queue[front];
    if(front==rear)
        front=rear=-1;
    else{
        if(front==MAX-1)
            front=0;
        else
            front++;
    }
    return val;
}

int peek(){
    if(front== -1 && rear==-1){
        cout<<"\n Queue is empty";
        return -1;
    }
    else
        return queue[front];
}

void display(){
    int i;
    cout<<endl;
    if(front==-1 && rear==-1)
        cout<<"\n Queue is empty";
    else{
        if(front<=rear){
            for(i=front;i<=rear;i++)
                cout<<"\t "<<queue[i];
        }
        else{
            for(i=front;i<MAX;i++)
                cout<<"\t "<<queue[i];
            for(i=0;i<=rear;i++)
                cout<<"\t "<<queue[i];
        }
    }
}
