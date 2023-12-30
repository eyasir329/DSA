#include<iostream>
#include<algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

// preorder build of the tree ROOT>LEFT>RIGHT
Node *buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

// preorder traversal ROOT>LEFT>RIGHT
void printPreorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// height
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+max(h1,h2);
}

// diameter O(N*N)
int diameter(Node *root){
    // base case
    if(root==NULL){
        return 0;
    }
    // rec case
    int D1 = height(root->left)+height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1,max(D2,D3));
}

int main(){
    // Input   : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    printPreorder(root);
    cout<<endl;
    int d = diameter(root);
    cout<<"Diameter :"<<d<<endl;
    return 0;
}