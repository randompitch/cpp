#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

int length(Node* head){
    int len{0};
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void insertAtHead(Node* &head,int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    while(temp-> next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void displayLL(Node* head)
{
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void intersect(Node* head1, Node* head2, int pos)
{
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;

}

int intersection(Node* &head1, Node* &head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int diff{0};
    Node* ptr1;
    Node* ptr2; 

    if(l1>l2){
        diff = l1-l2;
        ptr1 = head1; 
        ptr2 = head2;
    }
    else{
        diff = l2-l1;
        ptr1= head2; 
        ptr2= head1;
    }

    while(diff--){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
    }
     
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    intersect(head1, head2, 5);
    cout << "List 1: ";  displayLL(head1);
    cout << "List 2: "; displayLL(head2);
    cout << "Lists intersecting at : " << intersection(head1,head2) << endl; 
  
    return 0;
}