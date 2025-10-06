#include <iostream>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int val) : key(val), left(nullptr), right(nullptr){}
};

void insert(node *& root, int val){
    if(root == nullptr) root = new node(val);
    else if(root->key > val) insert(root->left, val);
    else insert(root->right, val);
}

void find_path(node* root, string direction){
    node* cur = root;
    for(char c : direction){
        if(c == 'L') cur = cur->left;
        else cur = cur->right;
        if (cur == nullptr){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    node* root = nullptr;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        insert(root, val);
    }
    for(int i=0; i<m; i++){
        string direction;
        cin >> direction;
        find_path(root, direction);
    }
    return 0;
}