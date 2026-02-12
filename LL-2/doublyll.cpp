#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
} ;

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printReverse(Node* tail){
    Node* temp = tail;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void insertAtHead(int value, Node* &head, Node* &tail){                                       
    // 2 cases -> LL is empty /non-empty
    //empty wala case
    if(head == NULL && tail == NULL){
        //iska matlab phele node create krnege 
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    //2 cases -> LL is empty / non-empty
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not empty
        // step 1: create a new node
        Node* newNode = new Node(value);
        // step 2: connect tail with new node
        tail->next = newNode;
        // step 3: connect new node with tail node 
        newNode->prev = tail;
        // step 4:
        tail = newNode;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtPosition(int position, int value, Node* &head, Node* &tail){
    // leftmost rightmost ya middle me insert krna chahte ho

    int len = getLength(head);

    if(position == 1){
        // insert leftmost me krna chahte h
        insertAtHead(value, head, tail);
    }
    else if(position == len+1){
        // insert rightmost end me krna chahte h
        insertAtTail(value, head, tail);
    }
    else{
        // middle me kisi position pe insert krna chahte h
        Node* temp = head;
        // fir mai temp ko position-2 steps aage badhayenge
        for(int i = 0; i < position-2; i++){
            temp = temp->next;
        }
        // Create node
        Node* newNode = new Node(value);
        // Forward pointer set
        Node* forward = temp->next;
        // pointers ko set kre
        newNode->prev = temp;
        temp->next = newNode;
        forward->prev = newNode;
        newNode->next = forward;
    }
}

bool searchElement(Node* &head, int target){ 
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtPosition(int position, Node* &head, Node* &tail){
    int length = getLength(head);
    // LL is empty
    if(head == NULL && tail == NULL){
        cout << "no nodes to delete" << endl;
        return;
    }
    else if(head == tail){
        // single node to delete
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if(position == 1){
        // we want to delete head node 
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(length == position){
        //we want to delete the tail node
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        // we want to delete any other node than head and tail node 
        Node* backword = head;
        for(int i = 0; i < position-2; i++){
            backword = backword->next;
        }
        Node* curr = backword->next;
        Node* forword = curr->next;
        
        //pointers change
        backword->next = forword;
        forword->prev = backword;

        //curr ko isolate krna h
        curr->prev = NULL;
        curr->next = NULL;

        // curr isolate ho chuka h
        delete curr;
    }
}

int main(){  
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtTail(10, head, tail);
    // 10 -> NULL;
    insertAtTail(20, head, tail);
    // 10 -> 20 -> NULL
    insertAtTail(30, head, tail);
    // 10 -> 20 -> 30 -> NULL

    /* insertAtHead(10, head, tail);
    //10->NULL
    insertAtHead(20, head, tail);
    // 20->10->NULL
    insertAtHead(30, head, tail);
    // 30->20->10->NULL */

    print(head);
    // printReverse(tail);

    insertAtPosition(3, 420, head, tail);
    print(head);

    deleteAtPosition(1, head, tail);
    print(head);

    return 0;
}
