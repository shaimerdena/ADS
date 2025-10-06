#include <iostream>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;

    node(int val) : key(val), left(nullptr), right(nullptr){}
};

void insert(node *&root, int val){
    if(root == nullptr) root = new node(val);
    else if(val < root->key) insert(root->left, val);
    else insert(root->right, val);
}

int inorder(node *&root, int &count){
    if(root == nullptr) return 0;
    if((root->left != nullptr) && (root->right != nullptr)){
        count++;
    }
    inorder(root->left, count);
    inorder(root->right, count);
    return count;
}

int main(){
    int n;
    cin >> n;
    node *root = nullptr;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        insert(root, val);
    }
    int count = 0;
    cout << inorder(root, count);
    return 0;
}