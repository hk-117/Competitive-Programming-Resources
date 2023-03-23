#include<iostream>
using namespace std;

struct node{
    int vertex;
    struct node *next;
};

node *gnode;
void displayGraph(node *adj[],int no_of_nodes);
void deleteGraph(node *adj[],int no_of_nodes);
void createGraph(node *adj[],int no_of_nodes);

int main(){
    node *Adj[10];
    int i,no_of_nodes;
    cout<<"\n Enter the number of nodes in G: ";
    cin>>no_of_nodes;
    for(i=0;i<no_of_nodes;i++){
        Adj[i]=NULL;
    }
    createGraph(Adj,no_of_nodes);
    cout<<"\n The graph is: ";
    displayGraph(Adj,no_of_nodes);
    deleteGraph(Adj,no_of_nodes);
    return 0;
}
void createGraph(node *Adj[],int no_of_nodes){
    node *new_node, *last;
    int i,j,n,val;
    for(i=0;i<no_of_nodes;i++){
        last=NULL;
        cout<<"\n Enter the number of neighbours of "<<i<<": ";
        cin>>n;
        for(j=1;j<=n;j++){
            cout<<"\n Enter the neighbour "<<j<<" of "<<i<<": ";
            cin>>val;
            new_node=(node *) new node;
            new_node->vertex =val;
            new_node->next=NULL;
            if(Adj[i]==NULL)
                Adj[i]=new_node;
            else
                last->next = new_node;
            last=new_node;
        }
    }
}
void displayGraph(node *Adj[],int no_of_nodes){
    node *ptr;
    int i;
    for(i=0;i<no_of_nodes;i++){
        ptr=Adj[i];
        cout<<"\n The neighbours of node "<<i<<" are:";
        while(ptr !=NULL){
            cout<< "\t"<<ptr->vertex;
            ptr=ptr->next;
        }
    }
}
void deleteGraph(node *Adj[],int no_of_nodes){
    node *temp,*ptr;
    for(int i=0;i<no_of_nodes;i++){
        ptr=Adj[i];
        while(ptr!=NULL){
            temp=ptr;
            ptr=ptr->next;
            delete temp;
        }
        Adj[i]=NULL;
    }
}
