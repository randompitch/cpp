#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

struct queue
{
    Node *front, *rear;
    int size{0};
    queue(){
        front = rear = NULL;
    }
    void enqueue(int x){
        Node* temp = new Node(x);
        size++;
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue(){
        if(front == NULL){
            cout << "Queue Empty";
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
        size--;
    }
    void print(){
        cout << "Queue Elements: ";
        Node* curr = front;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "END" << endl;
    }
    int Size(){
        return size;
    }
    void shuffle(queue q)
    {
        Node* min = front;
        Node* temp = front;
        while(temp != NULL){
            if(temp->data < min->data){
                min = temp;
            }
            temp = temp->next;   
        }
        
    }

};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    cout << q.Size();
  
    return 0;
}