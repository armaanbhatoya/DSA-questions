#include<iostream>
#include<vector>
#include<queue>
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

void postorder(Node* node){//postorder transversal
    if(node == nullptr) return ;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>> levelOrder(Node* root){  //Level Order Transversal
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
void printLevelOrder(Node* root){
    vector<vector<int>> arr = levelOrder(root);
    cout<<"Level Order Transversal: "<<endl;
    for(auto it: arr){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->right = new Node(5);

    // postorder(root);
    // inorder(root);
    // postorder(root);

    printLevelOrder(root);

    return 0;
}