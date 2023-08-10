#include <iostream>
using namespace std;

class Node
{
    public:
    Node* previous;
    int data;
    Node* next;

    Node(int val){
        previous = NULL;
        data = val;
        next = NULL;
    }

};

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    if(head != NULL){
        head->previous = n;
    }
    head = n;

}

void insertAtTail(Node* &head, int val)
{
   
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    } 
    
    temp->next = n;
    n->previous = temp;

}

void deleteAtHead(Node* &head)
{
    Node* toDelete = head;
    head = head->next;
    head->previous = NULL;

    delete(toDelete);
}

void deletion(Node* &head, int pos)
{
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }
    temp->previous->next = temp->next;
    if(temp->next != NULL){
        temp->next->previous = temp->previous;
    }
    
    delete(temp);
}

void displayDoublyLinkedList(Node* head)
{
    while(head != NULL){
        cout << head -> data << " ";
        head = head ->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL  ;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    displayDoublyLinkedList(head);
    insertAtHead(head, 0);
    displayDoublyLinkedList(head);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    displayDoublyLinkedList(head);
    deletion(head, 1);    
    displayDoublyLinkedList(head);

    return 0;
}