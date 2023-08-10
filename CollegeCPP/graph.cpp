#include<iostream>
using namespace std;
#define MAX 1000

template <typename T> class vector 
{
    T* arr;
    int capacity;
    int current;
 
public:
    vector()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    ~vector()
    {
          delete [] arr;
    }
    void push_back(T data)
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
                for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
    void push_back(T data, int index)
    {
 
        // if index is equal to capacity then this
        // function is same as push defined above
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
    T get(int index)
    {
        if (index < current)
            return arr[index];
    }
    void pop() { current--; }
    int size() { return current; }
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
};
Queue* createQueue(unsigned capacity)
{
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
void push(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}
int pop(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

class Stack {
    int top;
public:
    int a[MAX]; // Maximum size of Stack
  
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};  
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}  
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}  
bool Stack::isEmpty()
{
    return (top < 0);
}

void addEdge(vector<int> adj, int s, int d)
{
    adj.push_back(d);
}
vector<int> bfsOfGraph(int V, vector<int> adj)
{
    vector<int> bfs_traversal;
    vector<bool> vis;
    for (int i = 0; i < V; ++i) {
        if (!vis.get(i)) {
            Queue* q = createQueue(V);
            vis.push_back(true, i);
            push(q, i);
            while (!isEmpty(q)) {
                int g_node = front(q);
                pop(q);
                bfs_traversal.push_back(g_node);
                for (int i=0; i < V; i ++) {
                    if (!vis.get(i)) {
                        vis.push_back(true, i);
                        push(q, adj.get(i));
                    }
                }
            }
        }
    }
    return bfs_traversal;
}

int main()
{
    
    
    return 0;
}