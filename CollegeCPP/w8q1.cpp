#include <iostream>
using namespace std;

class Node
{
    public:
    int data; 
    Node *right, *left;
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

void insert(Node* &root, Node* n){
    int rL;
    cout << "Enter 0 if you want to add in LEFT subtree, 1 for RIGHT for the root " << root->data << ": ";
    cin >> rL;
    if(rL == 1){
        if(root->right == NULL){
            root->right = n;
        }
        else{
            insert(root->right, n);
        }
    }
    else{
        if(root->left == NULL){
            root->left = n;
        }
        else{
            insert(root->left, n);
        }
    }
}

void create(Node* &root){
    int val;
    cout << "Enter value: ";    cin >> val;
    Node* n = new Node(val); 
    if(root == NULL){
        root = n;
    }
    else{
        insert(root, n);        
    }    
}

void traverse(Node* root){
    if(root != NULL){
        traverse(root->left);
        cout << root->data << " ";
        traverse(root->right);
    }
}

bool search(Node* root, int n){
    if(root == NULL){
        return 0;
    }
    if(root->data == n){
        return true;
    }
    else{
        if(search(root->left, n)){
            return true;
        }        
        else{
            return search(root->right, n);
        }
    }
    return 0;
}

void displaySubTree(Node* root, int val){
    if(search(root,val)){
        
    }
    else{
        cout << "Element not in tree." << endl;
    }
}

int main()
{
    Node* root = NULL;
    int ch;
    do
    {
        create(root);
        cout << "Enter 1 to add more: ";    cin >> ch;
    } while (ch == 1);
    traverse(root);
    search(root, 30) ? cout << "yes" : cout << "No";
  
    return 0;
}