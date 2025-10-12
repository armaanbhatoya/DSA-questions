#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int v){
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* node){//preorder transversal
    if(node == nullptr) return ;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){//inorder transversal
    if(node == nullptr) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->right = new Node(5);

    // preorder(root);
    inorder(root);

    return 0;
}