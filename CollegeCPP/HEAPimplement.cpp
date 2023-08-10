#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class maxHeap
{
    public:
    int *harr;
    int capacity, heap_size;

    maxHeap(int cap){
        heap_size = 0;  capacity = cap;
        harr = new int[cap];
    }

    void linearSearch(int key){
        for(int i = 0; i < heap_size; i++){
            if(harr[i] == key){
                cout << "Present." << endl;
                return;
            }
        }
        cout << "Missing." << endl;
    }

    void print(){
        for(int i = 0; i<heap_size ; i++){
            cout << harr[i] << " ";
        }   cout << endl;
    }

    int getRightChild(int i)    {return (2*i)+2;}
    int getLeftChild(int i)     {return (2*i)+1;}
    int getParent(int i)        {return (i-1)/2;}

    void insertKey(int key){
        if(heap_size == capacity){
            cout << "OVERFLOW" << endl;
            return;
        }
        heap_size++;
        int i = heap_size-1;
        harr[i] = key;

        while(i != 0 && harr[getParent(i)] < harr[i]){
            swap(harr[i], harr[getParent(i)]);
            i = getParent(i);
        }
    }

    void maxHeapify(int i){
        int l = getLeftChild(i);
        int r = getRightChild(i);
        int max = i;
        if(l < heap_size && harr[l] > harr[i])  { max = l;}
        if(r < heap_size && harr[r] > harr[i])  { max = r;}
        if(max != i){
            swap(harr[i], harr[max]);
            maxHeapify(max);
        }
    }

    int extractmax(){
        if(heap_size <= 0)  {return INT_MIN;}
        if(heap_size == 1){
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        maxHeapify(0);

        return root;
    }

    int getmax()    { return harr[0]; }

    void decKey(int i, int new_val){
        harr[i] = new_val;
        while(i != 0 && harr[getParent(i)] < harr[i]){
            swap(harr[getParent(i)], harr[i]);
            i = getParent(i);
        }
    }
    void deleteKey(int i){
        decKey(i ,INT_MAX);
        extractmax();    
    }
};

int main()
{
    int s;
    cout << "Enter size of heap: ";     cin >> s;
    maxHeap Heap(s);    cout << "Max Heap created." << endl;
    int opt, val;
    cout << "Select 0 to exit, otherwise:";
    cout << "\n1. Insert \n2. Search";
    cout << "\n3. Delete \n4. Get max";
    cout << "\n5. Extract max \n6. Print heap" << endl;
    do{
        cout << "---->";    cin >> opt;

        switch (opt)
        {
        case 0:
            break;
        case 1:
            cout << "Enter value to Insert in maxHeap:";    cin >> val;
            Heap.insertKey(val);    cout << endl;
            break;
        case 2:
            cout << "Enter value to search : ";     cin >> val;
            Heap.linearSearch(val);     cout << endl;
            break;
        case 3:
            cout << "Enter Index value to delete : ";     cin >> val;
            Heap.deleteKey(val);    cout << endl;
            break;
        case 4:
            cout << "Get max value: ";
            cout << Heap.getmax();    cout << endl;
            break;
        case 5:
            cout << "Extract max: ";    
            cout << Heap.extractmax();    cout << endl;
            break;
        case 6:
            cout << "Print maxHeap elements: ";
            Heap.print();   cout << endl;
            break;  
        default:
            cout << "Enter correct option: " << endl;
            break;
        }
    }while(opt != 0);

    return 0;
}