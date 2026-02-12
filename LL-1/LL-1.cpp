#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    // Constructor
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

//this function will return the head of the updated linked list
void InsertAtHead(int value, Node* &head, Node* &tail){
    //case1 : empty ll
    if(head == NULL && tail == NULL){
        //step 1: create new node
        Node* newNode = new Node(value);
        //step 2: point head and tail on that new node
        head = newNode;
        tail = newNode;
    }
    //case2 : non-empty ll
    else{
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: link the new node to the linked list
        newNode->next = head;
        //step 3: update the head to the first node
        head = newNode;
    }
    //return the head of the modified linked list
    //return head;
}

void InsertAtTail(int value, Node* &head, Node* &tail){
    // empty ll
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    // non-empty ll
    else{
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
}

void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool searchInLinkedList(int target, Node* head){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == target){
            return true;
        }
        else{
            temp = temp->next;
        }
    }
    return false;
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtPosition(int position, int value, Node* &head, Node* &tail){
    //valid range
    int len = getLength(head);
    if(position < 1 || position > len+1){
        cout << "value of position is out of bound" << endl;
        return;
    }
    if(position == 1){
        InsertAtHead(value, head, tail);
        return;
    }
    
    if(position == len+1){
        InsertAtTail(value, head, tail);
        return;
    }
    else{
        //step 1: Node Create
        Node* newNode = new Node(value);
        //step 2: temp var ko pos-1 se reach karaya 
        Node* temp = head;
        for(int i = 1; i <= position-2; i++){
            temp = temp->next;
        }
        //step 3: newNode ko temp->next se connect kraya
        newNode->next = temp->next;
        //step 4: temp ko newNode se connect kra
        temp->next = newNode;
    }
}

void deleteFromPosition(int position, Node* &head, Node* &tail){
    //invalid cases
    int len = getLength(head);
    if(position > len){
        return;
    }
    if(head == NULL && tail == NULL){
        return;
    }
    
    //postion = 1 and LL single node
    if(head == tail && position == 1){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    //LL has multiple nodes but position =1
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else{
        //either you are delete middle node or last node
        //step1: setup current/previous/forward
        Node* Previous = head;
        for(int i = 1; i < position-1; i++){
            Previous = Previous->next;
        }
        Node* Current = Previous->next;
        Node* Forward = Current->next;


        //current is isolated now
        
        // step2: update links
        Previous->next = Forward;  
        Current->next = NULL;
        //current is isolated now

        if(Current == tail){
            tail = Previous; 
        }
        delete Current;
        return;
    }
}

int main(){
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;
    
    InsertAtHead(10, head, tail);
    InsertAtHead(20, head, tail);
    InsertAtHead(30, head, tail);
    InsertAtTail(40, head, tail);
    printLinkedList(head);
    
    bool ans = searchInLinkedList(10, head);
    cout << boolalpha << ans << endl;

    int res = getLength(head);
    cout << res << " ";

    /* insertAtPosition(3, 500, head, tail);
    cout << endl << "modified list" << endl;
    printLinkedList(head); */

    deleteFromPosition(3, head, tail);
    cout << endl << "modified list" << endl;
    printLinkedList(head);

    return 0;
}