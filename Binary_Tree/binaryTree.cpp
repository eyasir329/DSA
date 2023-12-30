#include<iostream>
#include<queue>

using namespace std;

// Input   : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// preorder : 1 2 4 5 7 3 6 
// inorder : 4 2 7 5 1 3 6
// postorder: 4 7 5 2 6 3 1
/* level order :1 
                2 3 
                4 5 6 
                7       
*/

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

// inorder traversal LEFT>ROOT>RIGHT
void printInorder(Node *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

// posroder traversal LEFT>RIGHT>ROOT
void printPostorder(Node *root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

// levelorder traversal like BFS
void levelOrderPrint(Node *root){
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            // insert a new null for the next level
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

int main(){
    // Input   : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    cout<<"PreOrder Traversal"<<endl;
    printPreorder(root);
    cout<<endl;
    cout<<"InOrder Traversal"<<endl;
    printInorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal"<<endl;
    printPostorder(root);
    cout<<endl;
    cout<<"levelOrderPrint Traversal"<<endl;
    levelOrderPrint(root);
    return 0;
}