#include <iostream>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;

    node(int val) : key(val), left(nullptr), right(nullptr){}
};

void insert(node *& root, int val){
    if(root==nullptr) root = new node(val);
    else if(val < root->key) insert(root->left, val);
    else insert(root->right, val);
}

void greater_sum(node *&root, int &sum){
    if(root == nullptr) return;
    greater_sum(root->right, sum);
    sum += root->key;
    root->key = sum;
    cout << root->key << " ";
    greater_sum(root->left, sum);
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
    int sum = 0;
    greater_sum(root, sum);
    return 0;
}