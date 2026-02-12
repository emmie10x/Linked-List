#include<iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/* 
// Reverse Function (Iterative - Pass by Reference)
void reverseLinkedList(Node* &head){
    // If linked list is empty
    if(head == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    // Reverse links one by one
    while(curr != NULL){
        Node* forward = curr->next;  // Store next node
        curr->next = prev;           // Reverse current node's link
        prev = curr;                 // Move prev forward
        curr = forward;              // Move curr forward
    }

    // Update head to new first node
    head = prev;
}
*/

// Reverse Function (Recursive - Pass by Value)
Node* reverseLinkedList(Node* head, Node* prev){
    
    // Base case: If list becomes empty,
    // return prev which becomes new head
    if(head == NULL){
        return prev;
    }
    
    // Step 1: Process current node
    Node* curr = head;
    Node* forward = curr->next;  // Store next node

    // Reverse current node's link
    curr->next = prev;

    // Step 2: Recursively reverse remaining list
    // forward becomes new head
    // curr becomes new prev
    return reverseLinkedList(forward, curr);
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){

    // Creating Linked List: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    print(head);

    // Update head after reversing
    head = reverseLinkedList(head, NULL);

    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
 