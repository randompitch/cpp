#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* buildTreePRE(int preorder[], int inorder[], int start, int end)
{
    static int idx;

    if(start > end){
        return NULL;
    }

    int curr =  preorder[idx];
    idx++;
    Node* node = new Node(curr);
    
    if(start == end){
        return node;
    }
    
    int pos = search(inorder, start, end, curr);
    
    node->left = buildTreePRE(preorder, inorder, start, pos-1);
    node->right = buildTreePRE(preorder, inorder, pos+1, end);

    return node;
}

Node* buildTreePOST(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;

    if(start > end){
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);

    if(start == end){
        return node;
    }

    int pos = search(inorder, start, end, curr);

    node->right = buildTreePOST(postorder, inorder, pos+1, end);
    node->left = buildTreePOST(postorder, inorder, start, pos-1);

    return node;
}

void inorderPrint(Node* root)
{
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    
    Node* root = buildTreePRE(preorder, inorder, 0, 4);
    inorderPrint(root);
    cout << '\n';
    Node* postRoot = buildTreePOST(postorder, inorder, 0, 4);
    inorderPrint(postRoot);  
    return 0;
}