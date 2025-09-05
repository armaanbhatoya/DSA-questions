#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){ //constructor
            data = data1;
            next = next1;
        }
        Node(int data1){ 
            data = data1;
            next = nullptr;
        }
};


Node* convertarr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);              //head
        mover->next = temp;                        //mover      temp
        mover = temp;
    }
    return head;
}

void Node_traversal(Node* head){
    Node* temp = head;

    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> arr= {2,3,4,6};
    Node* head = convertarr2ll(arr);
    Node_traversal(head);
    return 0;
}