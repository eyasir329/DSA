#include<stdio.h>
#include<stdlib.h>

//node structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//function to create a node
struct node* createNode(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//searching operation
struct node* search(struct node* root,int value){
    if(root==NULL||root->data==value){
        return root;
    }else if(value>root->data){
        return search(root->right,value);
    }else{
        return search(root->left,value);
    }
}

//insertion
struct node* insert(struct node* root,int value){
    if(root==NULL){
        return createNode(value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }else{
        root->left=insert(root->left,value);
    }
    return root;
}

//to find the minimum value in a node
struct node* findMinimum(struct node* root){
    if(root==NULL){
        return NULL;
    }else if(root->left!=NULL){
        return findMinimum(root->left);
    }
    return root;
}

//deletion
struct node* delete(struct node* root,int value){
    //searching for the item to be deleted
    if(root==NULL){
        return root;
    }else if(value>root->data){
        root->right=delete(root->right,value);
    }else if(value<root->data){
        root->left=delete(root->left,value);
    }else{
        //no child node
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        //one child node
        else if(root->left==NULL||root->right==NULL){
            struct node* temp;
            if(root->left==NULL){
                temp=root->right;
            }else{
                temp=root->left;
            }
            free(root);
            return temp;
        }
        //two child node
        else{
            struct node* temp;
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

//inorder traversal
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

//main function
int main(){
    struct node* root;
    root = createNode(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root,45);
    insert(root,42);

    //print
    printf("In-Order Traversal\n");
    inorder(root);
    printf("\n");

    //search
    if(search(root,40)!=NULL){
        printf("40 found\n");
    }else{
        printf("Not Found\n");
    }
    
    //delete
    root = delete(root,30);
    printf("In-Order Traversal After Delete\n");
    inorder(root);
    printf("\n");
}