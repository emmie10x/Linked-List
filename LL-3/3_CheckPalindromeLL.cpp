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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* getMidNode(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool checkPalindrome(Node* head){
    // find length of LL
    int len = getLength(head);

    Node* mid = getMidNode(head);
    // update mid as per even/odd length
    // even length me mid as it is use krna
    // odd case me main finalMid, mid->next ko lenge
    Node* finalMid = NULL;
    if(len & 1){
        //odd
        finalMid = mid->next;
    }
    else{
        //even
        finalMid = mid;
    }
    // reverseLL starting from mid 
    reverseLinkedList(finalMid);
    //now i have 2 linked list with starting pointer as head and finalMid
    // compare and return true/false
    Node* temp = head;
    while(finalMid != NULL){
        if(temp->data != finalMid->data){
            return false;
        }
        temp = temp->next;
        finalMid = finalMid->next;
    }
    return true;
}

int main(){

    // creating list 1->2->3->4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    print(head);
    
    bool ans = checkPalindrome(head);

    if(ans){
        cout << "Linked List is Palindrome" << endl;
    }
    else{
        cout << "Linked List is NOT Palindrome" << endl;
    }
    
    return 0;
}
