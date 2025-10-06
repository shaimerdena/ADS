#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int key;
    node *left, *right;

    node(int val) : key(val), left(nullptr), right(nullptr){}
};

void insert(node *& root, int val){
    if(root==nullptr) root = new node(val);
    else if(val < root->key) insert(root->left, val);
    else if(val > root->key) insert(root->right, val);
    return;
}

int findDiameter(node* &root, int &diameter) {
    if (!root) return 0;

    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight + 1);

    return max(leftHeight, rightHeight) + 1;
}

int main(){
    int n;
    cin >> n;
    node *root = nullptr;

    for(int i=0; i<n; i++){
        int val; cin >> val;
        insert(root, val);
    }
    int diameter = 0;
    findDiameter(root, diameter);
    cout << diameter;
    return 0;
}