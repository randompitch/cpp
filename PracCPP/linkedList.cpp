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
    int count{0};
    //RECURSIVE METHOD
    if(head == NULL){
        return 0;
    }
    else{
        return 1+length(head->next);
    }
    /* NORMAL(iterative) METHOD
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;*/
}

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAfter(Node* node, int key, int val)
{
    if(node == NULL){
        cout << "previous node can't be null." << endl;
        return;
    }

    Node* n = new Node(val);

    if(key == node -> data){
        n->next = node->next;
        node->next = n;
    }

    while(node->data != key){
        node = node->next;
        if(node == NULL){
            return;
        }
    }
    n->next = node->next;
    node->next = n;

}

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;        
    }

    temp->next = n;   
}

void deleteHead(Node* &head)
{
    Node* toDelete = head;
    head = head->next;

    delete toDelete;

}

void deleteNode(Node* &head, int val)
{
    if(head == NULL){       //empty linked list
        return;
    }

    if(head->next == NULL){     //only 1 element in linked list
        deleteHead(head);
    }
    Node* temp = head;
    while (temp->next->data != val){
        temp = temp->next;                
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    
    delete toDelete;
}

Node* reverse(Node* &head)
{
    /* ITERATIVE METHOD
    Node* currPtr = head;
    Node* prevPtr = NULL;
    Node* nextPtr;

    while(currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr; */

    // RECURSIVE METHOD
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;

}

bool search(Node* head, int key)
{
    while(head != NULL)
    {
        if(head->data == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}

int midElement(Node* &head)
{
    /*
    int len = length(head);
    int mid = len/2;

    Node* temp = head;
    while(mid--){
        temp = temp->next;
    }
    return temp->data;*/

    Node* fastPtr = head;
    Node* slowPtr = head;
    if(head != NULL){
        while(fastPtr != NULL && fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
    }
    return slowPtr->data;
}

int calcFreq(Node* head, int key)
{
    int freq = 0;
    while(head != NULL){
        if(head->data == key){
            freq++;
        }
        head = head->next;
    }
    return freq;

}

int sumElements(Node* &head)
{
    // RECURSIVE METHOD  space complexity => O(n)
    Node* curr = head;
    if(curr == NULL){
        return 0;
    }
    return curr->data+sumElements(curr->next);

/*  ITERATIVE METHOD space complexity => O(1)
    int sum{0};
    while(curr != NULL){
        sum+= curr->data;
        curr = curr->next;
    }
    return sum;
*/
}

void displayList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" <<  endl;
    
}

int main()
{
    Node* head = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 3);      displayList(head);  
    insertAtHead(head, 0);      displayList(head);
    insertAfter(head, 1, 2);    displayList(head);
    insertAfter(head, 3, 4);    displayList(head);
    insertAtHead(head, -1);     displayList(head);
    insertAtTail(head, 6);      displayList(head);
    insertAfter(head, 4, 5);    displayList(head);
    insertAfter(head, 6, 7);    displayList(head);
    insertAtTail(head, 7);      displayList(head);
    cout << "Given key in linked list: ";
    search(head, 10)? cout << "Yes."  << endl : cout << "No." << endl;
    deleteNode(head, 4);
    cout << "Deletion process in linked list: " << endl;
    displayList(head);
    deleteHead(head);
    cout << "Deletion process at head in linked list: " << endl;
    displayList(head);
    cout << "Length of linked list is: " << length(head) << endl;
    cout << "Middle element is: " << midElement(head) << endl;
    cout << "Frequency of 7 is: " << calcFreq(head, 7) << endl;
    cout << "Reversing a linked list: " << endl;
    head = reverse(head);
    displayList(head);
    cout << "Sum of elements of linked list is: " << sumElements(head) << endl;
    
    return 0;
}