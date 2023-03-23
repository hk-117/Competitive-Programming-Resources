#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

node *tr;
void create_tree(node *tree){
    tree=NULL;
}

node *insertElement(node *tree, int val){
    node *ptr,*nodeptr,*parentptr;
    ptr =(node *) new node;
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree == NULL){
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr != NULL){
            parentptr=nodeptr;
            if(val < nodeptr->data)
                nodeptr=nodeptr->left;
            else
                nodeptr=nodeptr->right;
        }
        if(val < parentptr->data){
            parentptr->left=ptr;
        }
        else{
            parentptr->right=ptr;
        }
    }
    return tree;
}

void preorderTraversal(node *tree){
    if(tree != NULL){
        cout<< tree->data <<"\t";
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(node *tree){
    if(tree != NULL){
        inorderTraversal(tree->left);
        cout<< tree->data <<"\t";
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(node *tree){
    if(tree != NULL){
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        cout<< tree->data <<"\t";
    }
}

node *findSmallestElement(node *tree){
    if(tree==NULL || tree->left ==NULL){
        return tree;
    }
    else{
        return findSmallestElement(tree->left);
    }
}

node *findLargestElement(node *tree){
    if(tree == NULL || tree->right ==NULL){
        return tree;
    }
    else{
        return findLargestElement(tree->right);
    }
}

node *deleteElement(node *tree,int val){
    if(tree == NULL){
        cout<<"\n Value is not found in Tree";
    }
    else if( val < tree->data){
        tree->left=deleteElement(tree->left,val);
    }
    else if( val > tree->data){
        tree->right=deleteElement(tree->right,val);
    }
    else if(tree->left != NULL && tree->right != NULL){
        node *temp = findLargestElement(tree->left);
        tree->data= temp->data;
        tree->left=deleteElement(tree->left,temp->data);
    }
    else{
        node *temp=tree;
        if(tree->left == NULL && tree->right==NULL){
            tree=NULL;
        }
        else if(tree->left != NULL){
            tree= tree->left;
            delete temp;
        }
        else{
            tree=tree->right;
            delete temp;
        }
    }
    return tree;
}

int totalNodes(node *tree){
    if(tree==NULL){
        return 0;
    }
    else{
        return (totalNodes(tree->left)+totalNodes(tree->right)+1);
    }
}

int totalExternalNodes(node *tree){
    if(tree == NULL)
        return 0;
    else if(tree->left==NULL && tree->right==NULL){
        return 1;
    }
    else{
        return (totalExternalNodes(tree->left)+totalExternalNodes(tree->right));
    }
}

int totalInternalNodes(node *tree){
    if(tree==NULL || (tree->left==NULL && tree->right==NULL)){
        return 0;
    }
    else
        return (totalInternalNodes(tree->left)+totalInternalNodes(tree->right)+1);
}

int Height(node *tree){
    int leftheight,rightheight;
    if(tree==NULL)
        return 0;
    else{
        leftheight= Height(tree->left);
        rightheight=Height(tree->right);
        if(leftheight>rightheight)
            return leftheight+1;
        else
            return rightheight+1;
    }
}

node *mirrorImage(node *tree){
    node *ptr;
    if(tree!=NULL){
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr=tree->left;
        tree->left=tree->right;
        tree->right=ptr;
    }
    return tree;
}

node *deleteTree(node *tree){
    if(tree != NULL){
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
    tree=NULL;
    return tree;
}

int main(){
    int option,val;
    node *ptr;
    create_tree(tr);
    do{
        cout<<"\n ****** MAIN MENU ****** \n";
        cout<<"\n 1. Insert Element";
        cout<<"\n 2. Preorder Traversal";
        cout<<"\n 3. Inorder Traversal";
        cout<<"\n 4. Postorder Traversal";
        cout<<"\n 5. Find the smallest element";
        cout<<"\n 6. Find the largest element";
        cout<<"\n 7. Delete an element";
        cout<<"\n 8. Count the total number of nodes";
        cout<<"\n 9. Count the total number of external nodes";
        cout<<"\n10. Count the total number of internal nodes";
        cout<<"\n11. Determine the height of the tree";
        cout<<"\n12. Find the mirror image of the tree";
        cout<<"\n13. Delete the tree";
        cout<<"\n14. Exit";
        cout<<"\n Enter your option : ";
        cin>>option;
        switch(option){
            case 1:
                cout<<"\n Enter the value of the new node : ";
                cin>>val;
                tr=insertElement(tr,val);
                break;
            case 2:
                cout<<"\n The elements of the tree are : \n";
                preorderTraversal(tr);
                break;
            case 3:
                cout<<"\n The elements of the tree are : \n";
                inorderTraversal(tr);
                break;
            case 4:
                cout<<"\n The elements of the tree are : \n";
                postorderTraversal(tr);
                break;
            case 5:
                ptr=findSmallestElement(tr);
                cout<<"\n The smallest element is : "<< ptr->data ;
                break;
            case 6:
                ptr=findLargestElement(tr);
                cout<<"\n The largest element is : "<< ptr->data ;
                break;
            case 7:
                cout<<"\n Enter the element to be deleted : ";
                cin>>val;
                tr=deleteElement(tr,val);
                break;
            case 8:
                cout<<"\n Total no. of nodes = "<<totalNodes(tr);
                break;
            case 9:
                cout<<"\n Total no. of external nodes = "<<totalExternalNodes(tr);
                break;
            case 10:
                cout<<"\n Total no. of internal nodes = "<<totalInternalNodes(tr);
                break;
            case 11:
                cout<<"\n The height of the tree = "<<Height(tr);
                break;
            case 12:
                tr= mirrorImage(tr);
                break;
            case 13:
                tr= deleteTree(tr);
                break;
        }
    }while (option != 14);
    return 0;
}
