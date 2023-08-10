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

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        n->next = head;
    }
    else{
        n->next = head->next;
        head->next = n;
        int tempDat = head->data;
        head->data = n->data;
        n->data = tempDat;        
    }
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        n->next = head;
    }
    else{
        n->next = head->next;
        head->next = n;
        int tempDat = head->data;
        head->data = n->data;
        n->data = tempDat;
        head = n;
    }
}

void insertAtPos(Node* &head, int pos, int val){
    Node* n = new Node(val);
    Node* temp = head;
    if(pos == 1){
        insertAtHead(head,val);
    }
    else{
        for(int i = 1; i<=pos-2; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp->next != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " NULL" << endl;
}

int main()
{
    Node* head = NULL;
    int i;
    cout << "Enter 1 if you want to insert at head\n";
    cout << "Enter 2 if you want to insert at tail\n";
    cout << "Enter 3 if you want to insert at a given position\n";
    cout << "Enter 4 if you want to print the linked list\n";
    cout << "Enter 5 if you want to exit\n";
    do
    {
        cout << "Enter choice ---> ";   cin >> i;
        if(i==1){
            int num;
            cout << "Enter element to be added: "; cin >> num;
            insertAtHead(head, num);
        }
        else if (i==2)
        {
            int num;
            cout << "Enter element to be added: "; cin >> num;
            insertAtTail(head, num);
        }
        else if (i==3)
        {
            int num, pos;
            cout << "Enter element to be added: "; cin >> num;
            cout << "Enter position for element to be added: "; cin >> pos;
            insertAtPos(head,pos,num);
        }
        else if (i==4)
        {
            display(head);
        }
        else{
            break;
        }       
        
    } while (i != 5);
    return 0;
}