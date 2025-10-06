// Christmas is coming! Everyone is preparing gifts for their families. 
// The Damir's family is also preparing for this. The Damir's family has many children, so the parents decided to buy n various gifts. 
// Parents decided to number these gifts - i-th as aj. They hang them on Christmas tree in socks, following the form binary search tree. 
// In particular, they insert ith gift with the value a; following the rules of binary search tree.
// As you know, Damir is the smallest among the whole family. Therefore, parents for the holiday allowed him to pick up his gift first. 
// Damir knew that his gift has number k, but he mistakenly assumed that all the gifts below his gift were also intended for him.
// Now, parents are confused and want to find out what gifts Damir wants to grab for himself.


#include <iostream>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int val) : key(val), left(nullptr), right(nullptr) {} 
};

void insert(node *&root, int val){
    if(root == nullptr) root = new node(val);
    else if(val > root->key) insert(root->right, val);
    else insert(root->left, val); 
}

void preorder(node *root){
    if(root == nullptr) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void finding(node *root, int target){
    if(root->key == target) preorder(root);
    else if(root->key < target) finding(root->right, target);
    else finding(root->left, target);
}


int main(){
    int n;
    cin >> n;
    node *root = nullptr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }
    int target;
    cin >> target;
    finding(root, target);
    return 0;
}