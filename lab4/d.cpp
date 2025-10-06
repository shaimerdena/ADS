#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int key;
    node *left, *right;

    node(int val) : key(val), left(nullptr), right(nullptr){}
};

void insert(node *& root, int val){
    if(root == nullptr) root = new node(val);
    else if(val<root->key) insert(root->left, val);
    else insert(root->right, val);
}

void find_sum(node *& root){
    vector<int> v;
    queue<node*> q;
    q.push(root);
    int count = 1;
    while(!q.empty()){
        int sum = 0;
        int s = q.size();
        for(int i=0; i<s; i++){
            node *curr = q.front();
            sum += curr->key;
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        v.push_back(sum);
    }
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    node *root = nullptr;

    for(int i = 0; i<n; i++){
        int val;
        cin >> val;
        insert(root, val);
    }
    find_sum(root);
    return 0;
}