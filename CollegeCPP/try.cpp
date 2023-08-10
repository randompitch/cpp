#include <iostream>

using namespace std;

class Node
{
    public:
    int data; Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void createLL(Node* &head){
    int ch;
    Node* curr = NULL;
    do{
        int num;
        cout << "Enter value you want to add: ";    cin >> num;
        Node* n = new Node(num);
        if(head == NULL){
            head = n;
            curr = n;
        }
        else{
            curr->next=n;
            curr=n;
        }
        cout << "Enter 1 to add more: ", cin >> ch;
    }while(ch == 1);
}

void display(Node* head){
    cout << "Linked list: ";
    while(head != NULL){
        cout << head->data<< " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtMid(Node* &head){
    int val; 
    cout<< "Enter element to add to middle of list: ";    cin >> val;
    //cout << val;
    Node* n = new Node(val);
    //cout << 2;
    if(head == NULL){
        head = n;
        return;
    }
    Node* slowPtr = head;
    //cout << slowPtr->data;
    Node* fastPtr = head;
        while(fastPtr != NULL && fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
    //cout << slowPtr->data;
    n->next = slowPtr->next;
    slowPtr->next = n;
}

int main()
{
    Node* head = NULL;
    createLL(head);
    display(head);
    insertAtMid(head);
    display(head);
    return 0;
}