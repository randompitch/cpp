#include <iostream>
using namespace std;

class Node
{
    public:
    int data, height;
    Node *left, *right;
    Node(int v){
        data = v;   height = 1;
        left = NULL;    right = NULL;
    }
};

int max(int x, int y)       {return (x > y) ? x : y;}

int height(Node* n)
{
    if(n == NULL)       {return 0;}
    return n->height;
}

int getBF(Node* n)
{
    if(n == NULL)   {return 0;}
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* x)
{
    Node* y = x->left;
    Node* T3 = y->right;

    y->right = x;
    x->left = T3;

    x->height = 1+ max(height(x->left), height(x->right));
    y->height = 1+ max(height(y->left), height(y->right));

    return y;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T3 = y->left;

    y->left = x;
    x->right = T3;

    x->height = 1+ max(height(x->left), height(x->right));
    y->height = 1+ max(height(y->left), height(y->right));

    return y;
}

Node* insertAVL(Node* root, int val)
{
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data)        { root->left = insertAVL(root->left, val); }
    else if(val > root->data)   { root->right = insertAVL(root->right, val); }
    else                        { return root; }

    root->height = 1 + max(height(root->left), height(root->right));

    int bF = getBF(root);
    if(bF > 1 && val < root->left->data){
        return rightRotate(root);
    }
    if(bF < -1 && val > root->right->data){
        return leftRotate(root);
    }
    if(bF > 1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bF < -1 && val < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    } 

    return root;
}

Node* minValNode(Node* root)
{
    Node* curr = root;
    while(curr->left != NULL)   {curr = curr->left;}
    return curr;
}

Node* deleteAVL(Node* root, int val)
{
    if(root == NULL)    {return root;}
    
    if(val < root->data)    {root->left = deleteAVL(root->left, val);}
    else if(val > root->data)       {root->right = deleteAVL(root->right, val);}
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = minValNode(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }
    if(root == NULL)    {return root;}
    root->height = 1 + max(height(root->left), height(root->right));

    int bF = getBF(root);
    if(bF > 1 && getBF(root->left) >= 0){
        return rightRotate(root);
    }
    if(bF < -1 && getBF(root->left) <= 0){
        return leftRotate(root);
    }
    if(bF > 1 && getBF(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bF < -1 && getBF(root->left) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    } 

    return root;    
}

void inorder(Node* root)
{
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insertAVL(root, 9);
    root = insertAVL(root, 5);
    root = insertAVL(root, 10);
    root = insertAVL(root, 0);
    root = insertAVL(root, 6);
    root = insertAVL(root, 11);
    root = insertAVL(root, 1);
    root = insertAVL(root, 2);

    cout << "Inorder of AVL : ";     inorder(root);
    root = deleteAVL(root, 5);
    cout << "\nInorder of AVL after deleting 5 : ";     inorder(root);
    cout << "\nPreorder of AVL after deleting 5 : ";     preOrder(root);
  
    return 0;
}