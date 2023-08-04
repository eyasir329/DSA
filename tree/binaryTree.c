#include<stdio.h>
#include<stdlib.h>

//declare node of the binary tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//create a new of binary tree
struct node* createNode(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//insert of the left of the node
struct node* insertLeft(struct node* root,int value){
    root->left=createNode(value);
    return root->left;
}

//insert of the right of the node
struct node* insertRight(struct node* root,int value){
    root->right=createNode(value);
    return root->right;
}

//traverse of binary tree
//preorder
void preorderTraversal(struct node* root){
    if(root==NULL) return;
    printf("%d->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//inorder
void inorderTraversal(struct node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d->",root->data);
    inorderTraversal(root->right);
}

//postorder
void postorderTraversal(struct node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d->",root->data);
}

int main(){
    struct node* root=createNode(1);
    insertLeft(root,45);
    insertRight(root,36);
    insertLeft(root->left,27);
    insertRight(root->left,31);
    insertLeft(root->right,24);
    insertRight(root->right,46);

    printf("Traversal of the inserted Binary Tree\n");

    printf("In-Order Traversal\n");
    inorderTraversal(root);

    printf("\nPre-Order Traversal\n");
    preorderTraversal(root);

    printf("\nPost-Order Traversal\n");
    postorderTraversal(root);
    printf("\n");
}