#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Print Function
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseKGroup(Node* head, int k){

    if(head == NULL){
        return NULL;
    }

    // Step 1: Check if k nodes exist
    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < k){
        temp = temp->next;
        count++;
    }

    if(count < k){
        return head;  // not enough nodes
    }

    // Step 2: Reverse k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursive call
    if(next != NULL){
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

int main(){

    // Creating list: 1->2->3->4->5->6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    print(head);

    int k = 2;

    head = reverseKGroup(head, k);

    cout << "After Reversing in Groups of " << k << ": ";
    print(head);

    return 0;
}
