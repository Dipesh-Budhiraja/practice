#include "header.h"
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int data = this->data;
        if (this->next != NULL) {
            this->next = NULL;
        }
        cout << "memory freed for node " << data << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d) {
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = head;
    }
}

void insertAtTail(Node* &tail, int d) {
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

void printLL(Node* &head) {
    Node *trav = head;

    while(trav != NULL) {
        cout << trav->data << " ";
        trav = trav->next;
    }
    cout << endl;
}

void insertAtPos(Node* &head, Node* &tail,int pos, int d) {
    // insert at begin
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node *newNode = new Node(d);
    
    Node *trav = head;
    int cnt = 1;
    while(cnt < pos-1) {
        trav = trav->next;
        cnt++;
    }
    

    // update tail when inserting at the last position
    if (trav->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    newNode->next = trav->next;
    trav->next = newNode;
}

void deleteNode(int position, Node* &head) {
    // tail is not handled currently. ho jaega aram se

    // delete first node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node *pre = NULL;
        Node *cur = head;
        int cnt = 1;
        while (cnt < position)
        {
            pre = cur;
            cur = cur->next;
            cnt++;
        }
        
        pre->next = cur->next;
        delete cur;
    }
}


int main() {
    
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 15);
    insertAtPos(head, tail, 1, 8);
    insertAtTail(tail, 7);
    insertAtTail(tail, 5);
    insertAtTail(tail, 3);
    insertAtPos(head, tail, 8, 2);
    insertAtTail(tail, 1);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    printLL(head);

    deleteNode(1, head);
    printLL(head);

    deleteNode(3, head);
    printLL(head);

    return 0;
}