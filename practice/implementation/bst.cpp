#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

void insert(Node *&root, int val){
    if(root == nullptr){
        root = new Node(val);
    }
    else if(val < root->key){
        insert(root->left, val);
    }
    else{
        insert(root->right, val);
    }
}

Node* findNode(Node *root, int val){
    if(root == nullptr) return nullptr;
    if(val == root->key) return root;
    else if(val > root->key) return findNode(root->right, val);
    else return findNode(root->left, val);
}

Node* findMin(Node *root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

void delete_node(Node *root, int val){
    if(root == nullptr) return;
    root = findNode(root, val);
    if(!root->left){
        Node *temp = root->right;
        delete temp;
        return;
    }
    else if(!root->right){
        Node *temp = root->left;
        delete temp;
        return;
    }
    Node* temp = findMin(root->right);
    root->key = temp->key;
    delete_node(root->right, temp->key);
}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if(!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}



int main(){
    int n;
    cin >> n;
    Node *root = nullptr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}