#include <iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

int search(Node* &head, int key)
{
    Node* temp = head;
    int pos=0;
    while(temp != NULL){
        if(temp->data == key){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display(Node* head)
{
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void create(Node* &head)
{
    int val, idx;
    cout << "\tEnter number: "; cin >> val;
    idx = search(head, val); 
    if(idx != -1){
        cout << "Element already exists in list at index " << idx << endl;
    }
    else{
        insertAtTail(head, val);
    }
}

void swap(Node* node1, Node* node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void bubbleSort(Node* head)
{
    Node* end = NULL; 
    Node* i = NULL; 
    Node* j = NULL;
    for(end = NULL; end != head->next; end = i){
        for(i = head; i->next != end; i = i->next){
            j = i->next;
            if(i->data > j->data){
                swap(i,j);
            }
        }
    }

}

void insertionSort(Node* head)
{

}

void selectionSort(Node* head)
{
    Node* temp = head;
    while(temp){
        Node* min = temp;
        Node* i = temp->next;
        while(i){
            if(min->data > i->data){
                min = i;
            }
            i = i->next;
        }
        swap(temp, min);
        temp = temp->next;
    }
}

void deleteNode(Node* &head)
{
    if(head == NULL){
        cout << "\tList is empty. UNDERFLOW!!!!" << endl;
        return;
    }
    cout << "\tOriginal List is: "; display(head);
    if(head->next == NULL){
        cout << "\tSingle element in list, deleted" << endl;
        //Node* toDel = head;
        head = head->next;
        //delete toDel;
        delete head;
        cout << "\tList after deleting the node: "; display(head);
        return;
    }
    int val;
    cout << "\tEnter element to delete: "; cin >> val;
    Node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "\tList after deleting the node: "; display(head);
}

int main()
{
    Node* head = NULL;
    int ch;
    do
    {
        cout << "\nEnter 1 to create a list" << endl;
        cout << "Enter 2 to display the list" << endl;
        cout << "Enter 3 to sort the list" << endl;
        cout << "Enter 4 to delete a node in the list" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "  ---->  ";   cin >> ch;
        cout << endl;
        if(ch == 1){
            create(head);
        }
        else if(ch == 2){
            cout << "\t The list is: ";
            display(head);
        }
        else if(ch == 3){
            int ch1;
            cout << "\tEnter 1 to use bubble sort" << endl;
            cout << "\tEnter 2 to use insertion sort" << endl;
            cout << "\tEnter 3 to use selection sort" << endl;
            cout << "\t  ---->  ";    cin >> ch1;
            if(ch1 == 1){
                cout << "\t\tUnsorted list: ";  display(head);
                bubbleSort(head);
                cout << "\t\tSorted list: ";  display(head);
            }
            else if(ch1 == 2){
                cout << "Unsorted list: ";  display(head);
                insertionSort(head);
                cout << "Sorted list: ";  display(head);
            }
            else if(ch1 == 3){
                cout << "Unsorted list: ";  display(head);
                selectionSort(head);
                cout << "Sorted list: ";  display(head);
            }
        }
        else if(ch == 4){
            deleteNode(head);
        }
    } while (ch != 0);
    
    return 0;
}