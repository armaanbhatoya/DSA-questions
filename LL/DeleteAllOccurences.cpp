// Delete all occurrences of a key in DLL

// Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.


#include <iostream>
using namespace std;

// Definition for doubly-linked list.
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};


// Function where YOU will write the logic  ****************************************************************
Node* deleteAllOccurrences(Node* head, int target) {

    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == target){
            if(temp == head){
                head = head->next;
                if(head != nullptr)
                    head->prev = nullptr;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;
            delete temp;
            temp = nextNode;
        }
        else temp =temp->next;
    }

    return head;
}// ********************************************************************************************************8


// Helper function to insert at end
Node* insertAtEnd(Node* head, int val) {

    Node* newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


// Helper function to print list forward
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Helper function to print list backward
void printReverse(Node* head) {

    if (head == NULL)
        return;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}


// Main function for practice
int main() {

    Node* head = NULL;

    // Creating list: 1 2 3 2 4 2 5
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 5);

    cout << "Original List:\n";
    printList(head);

    int target;
    cout << "Enter target to delete: ";
    cin >> target;

    head = deleteAllOccurrences(head, target);

    cout << "Modified List:\n";
    printList(head);

    return 0;
}
