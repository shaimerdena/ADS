// Problem B: 105587. Get subtree

// You are given Binary Search Tree. Your task is to calculate the size of the subtree of the node X.

// Remember, that the subtree of node X is the set of all nodes whose ancestor is node X, including it. The size of the subtree is the size of such set.

#include <iostream>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int val) : key(val), left(nullptr), right(nullptr) {}
};

void insert(node* &root, int val){
    if(root == nullptr){
        root = new node(val);
    }
    else if(val < root->key){
        insert(root->left, val);
    }
    else{
        insert(root->right, val);
    }
}

int findSize(node*root){
    if(root == nullptr) return 0;
    return 1 + findSize(root->left) + findSize(root->right);
}

node* findNode(node* root, int val){
    if(root == nullptr) return nullptr;
    if(root->key == val) return root;
    else if(val < root->key) return findNode(root->left, val);
    else return findNode(root->right, val);
}


int main(){
    int n;
    cin >> n;
    node* root = nullptr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }
    int target;
    cin >> target;
    node* targetNode = findNode(root, target);
    cout << findSize(targetNode) << endl;
    return 0;
}