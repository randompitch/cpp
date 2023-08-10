#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int v){
        data = v;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root)
{
    if(root == NULL){
        return 0;
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

int diameter(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh+rh+1, max(ld, rd));
    
}

bool isBalanced(Node* root)
{
    if (root == NULL)
    {
        return 1;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return 1;
    }

    return 0;
    
}

bool isBST(Node* root, int min, int max)
{
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return isBST(root->left, min, root->data-1) && isBST(root->right, root->data+1, max);
}

Node* arrToBST(int arr[], int start, int end)
{
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left = arrToBST(arr, start, mid-1);
    root->right = arrToBST(arr, mid+1, end);

    return root;
}

void preOrder(Node* root)
{
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void printCurrLevel(Node* root, int level)
{
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
    }
    else if(level > 1){
        printCurrLevel(root->left, level-1);
        printCurrLevel(root->right, level-1);
    }
}

void sumAtLEvel(Node* root, int level, int sum[])
{
    if(root == NULL){
        return;
    }

    sum[level] += root->data;

    sumAtLEvel(root->left, level+1, sum);
    sumAtLEvel(root->right, level+1, sum);
}

void levelOrder(Node* root)
{
    int h = height(root);
    int i;
    for(int i = 1; i<=h; i++){
        printCurrLevel(root, i);
    }
}

int search(int arr[], int st, int end, int key)
{
    for(int i=st; i<= end; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int in[], int pre[], int st, int end)
{
    static int idx = 0;
    if(st>end){
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    Node* root = new Node(curr);
    if(st == end){
        return root;
    }
    int pos = search(in, st, end,curr);
    root->left = buildTree(in, pre, st, pos-1);
    root->right = buildTree(in, pre, pos+1, end);

    return root;
    
}

Node* buildTreePost(int post[], int in[], int st, int end)

{
    static int idx = 4;
    if(st>end){
        return NULL;
    }
    int curr = post[idx];
    idx--;
    Node* root = new Node(curr);
    if(st == end){
        return root;
    }

    int pos = search(in, st, end, curr);
    root->right = buildTreePost(post, in, pos+1, end);
    root->left = buildTreePost(post, in, st, pos-1);
    
    return root;

}

void sumTree(Node* root, int *sum)
{
    if(root == NULL){
        return;
    }
    sumTree(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum - root->data;
    sumTree(root->left, sum);

}

void mirror(Node* node)
{
    if (node == NULL)
        return;
    else {
        Node* temp;
 
        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void kthLargestUtil(Node *root, int k, int &c)
{
    if (root == NULL || c >= k)
        return;
  
    kthLargestUtil(root->right, k, c);
    c++;
    if (c == k){
        cout << "K'th largest element is " << root->data << endl;
        return;
    }

    kthLargestUtil(root->left, k, c);
}
  
void kthLargest(Node *root, int k)
{
    int c = 0;
    kthLargestUtil(root, k, c);
}

int main()
{
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height : " << height(root) << endl;
    cout << "Diameter : " << diameter(root) << endl;
    isBalanced(root) ? cout << "yes\n" : cout << "no\n";
    isBST(root, INT_MIN, INT_MAX) ? cout << "yes\n" : cout << "no\n"; 
    
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    Node * root2 = arrToBST(arr, 0, n-1);
    cout << "Preorder: ";   preOrder(root2);
    cout << "\nLevel Order: ";    levelOrder(root);
    cout << "\nLevel Order: ";    levelOrder(root2);

    int levels = height(root)+1;
    int sum[levels] = {0};
    sumAtLEvel(root, 0, sum);
    cout << "\nSum at 2nd level: " << sum[2] << endl; 

    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node* root3 = buildTree(inorder, preorder, 0, 4);
    cout << "inorder: ";   inOrder(root3);

    int postorder[] = {4,2,5,3,1};
    Node* root4 = buildTreePost(postorder, inorder, 0, 4);
    cout << "inorder: ";   inOrder(root4);

    struct Node *root5 = new Node(11);
    root5->left = new Node(2);
    root5->right = new Node(29);
    root5->left->left = new Node(1);
    root5->left->right = new Node(7);
    root5->right->left = new Node(15);
    root5->right->right = new Node(40);
    root5->right->right->left = new Node(35);
    int s = 0;
    sumTree(root5, &s);
    cout << "\nin Order: ";    inOrder(root5);

    return 0;
}