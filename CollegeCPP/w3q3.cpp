#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void display(node* head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;    
}//24, 6, 7, 8, 1, 2, 8, 10, 4, 27, 16, 26.

node* copyLL(node* head){
    if(head == NULL){
        return NULL;
    }
    else{
        node* n = new node(head->data);
        n->next = copyLL(head->next);
        return n;
    }
}

void swap(node* n1, node* n2){
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

void sort(node* head){
    node* end=NULL;
    node* i=NULL;
    node* j=NULL;
    for(end = NULL; end != head->next; end = i){
        for(i = head; i->next != end; i = i->next){
            j = i->next;
            if(i->data > j->data){
                swap(i,j);
            }
        }
    }
}

node* merge(node* h1, node* h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
 
    if (h1->data < h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

int main()
{
    node* SLL1 = NULL;
    int dat;
    do{
        cout << "Enter value to add to list, enter -1 if done adding : "; cin >> dat;
        if(dat >= 0)
            insertAtTail(SLL1, dat);
    }while(dat != -1);
    cout << "SLL1: ";   display(SLL1);
    node* SLL2 = copyLL(SLL1);
    cout << "SLL2: ";   display(SLL2);
    sort(SLL2);
    cout << "After sorting SLL2: "; display(SLL2);
    sort(SLL1);
    node* mergedLL = merge(SLL1, SLL2);
    cout << "Merged linked list: "; display(mergedLL);

    return 0;
}