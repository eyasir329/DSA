#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};

// inserting
Node *insert(Node *root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;
}

//inorder traversal
void printInorder(Node *root){
    if(root==NULL){
        return;
    }
    // left>root>right
    printInorder(root->left);
    cout<<root->key<<", ";
    printInorder(root->right);
} 

// searching
bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    if(key<root->key){
        return search(root->left,key);
    }
    return search(root->right,key);
}

// minimum
Node *findMin(Node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

// deletion
Node *remove(Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    else if(key<root->key){
        root->left = remove(root->left,key);
    }
    else if(key>root->key){
        root->right = remove(root->right,key);
    }
    else{
        // when the current node matches with the key
        // three remove cases

        // No children
        if(root->left==NULL and root->right==NULL){
            delete root;
            root=NULL;
        }
        // single children
        else if(root->left==NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }else{
            // two children
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right,temp->key);
        }
    }
    return root;
}

// print all element of BST which lie in the range k1 and k2
void printRange(Node *root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->key>=k1 and root->key<=k2){
        // call in both sides
        printRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printRange(root->right,k1,k2);
    }else if(root->key>k2){
        printRange(root->left,k1,k2);
    }else{
        printRange(root->right,k1,k2);
    }
}


int main(){
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root = insert(root,x);
    }
    printInorder(root);
    // int num;
    // cout<<endl;
    // cout<<"Enter a key for deletion:"<<endl;
    // cin>>num;
    // if(search(root,num)){
    //     cout<<"Found it"<<endl;
    // }else{
    //     cout<<"Not Found"<<endl;
    // }
    // root = remove(root,num);
    // cout<<"After deletion :"<<endl;
    // printInorder(root);
    int k1,k2;
    cin>>k1>>k2;
    printRange(root,k1,k2);
    return 0;
}