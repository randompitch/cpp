#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* &root, int v)
{
    Node* n = new Node(v);
    if(root == NULL){
        return n;
    }
    else{
        if(v < root->data){
            root->left = insertBST(root->left, v);
        }
        else if(v > root->data){
            root->right = insertBST(root->right, v);
        }
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

Node* maxValNode(Node* root)
{
    Node* curr = root;
    while(curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

Node* deleteBST(Node* root, int v)
{
    if(root == NULL){
        return root;
    }
    if(v < root->data){
        root->left = deleteBST(root->left, v);
    }
    else if(v > root->data){
        root->right = deleteBST(root->right, v);
    }
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
            Node* temp = maxValNode(root->left);
            root->data = temp->data;
            root->left = deleteBST(root->left, temp->data);
        }        
    }
    return root;
}

int height(Node* root)
{
	if(root == NULL){
    	return -1;
	}
	else{
    	int lheight = height(root->left);
    	int rheight = height(root->right);
    	if(lheight > rheight){
        	return lheight+1;
    	}
    	else{
        	return rheight+1;
    	}
	}
}


int main()
{
    Node* root = NULL;
    char w;
    do{
        int ch;
        cout << "\nEnter 1 to insert\n 2 to delete\n 3 to print inorder traversal\n ";
        cout << "-->";      cin >> ch;
        if(ch == 1){
            int v;     
            cout << "\nEnter Value to Insert: ";     cin >> v;
            root = insertBST(root, v);
        }
        else if(ch == 2){
            int v;     
            cout << "\nEnter Value to Delete: ";     cin >> v;
            root = deleteBST(root, v);
        }
        else if(ch == 3){
            cout << "\nIn order Traversal: ";
            inorder(root);
            cout << endl;
        }
        else{
            cout << "Invalid Input! Try Again!!" << endl;
        }
        cout << "\nEnter x to exit";      cin >> w;
    }while(w != 'x');
    
    cout << endl << height(root);
  
    return 0;
}