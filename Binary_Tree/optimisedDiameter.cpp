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

class HDPair{
    public:
    int height;
    int diameter;
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

// optimised diameter O(N)
HDPair optDiameter(Node *root){
    HDPair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    // othercase
    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);

    p.height = max(Left.height,Right.height)+1;
    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;
    p.diameter = max(D1,max(D2,D3));
    return p;
}

int main(){
    // Input   : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    printPreorder(root);
    cout<<endl;
    int d = optDiameter(root).diameter;
    cout<<"Diameter :"<<d<<endl;
    return 0;
}