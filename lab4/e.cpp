// Given a binary tree, write a program to get the width of the given tree.

// The level of a node is the number of vertices on the path from this node to the root. 
// The width of a level h is the number of vertices with level h. 
// The width of a tree is the maximal width over the levels.

// Vertex number 1 always will be root.

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;

    node(int val) : key(val), left(nullptr), right(nullptr) {}
};

int getWidth(node *root){
    queue<node*> q;
    q.push(root);
    int maxWidth = 0;
    while(!q.empty()){
        int count = q.size();
        maxWidth = max(maxWidth, count);
        for(int i=0; i<count; i++){
            node *curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return maxWidth;
}

int main(){
    int n;
    cin >> n;
    map<int, node*> mp;
    node *root = nullptr;
    root = new node(1);
    mp[1] = root;
    
    for(int i=0;i<n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(mp.find(x) == mp.end()){
            mp[x] = new node(x);
        }
        if(mp.find(y) == mp.end()){
            mp[y] = new node(y);
        }
        if(z == 0){
            mp[x]->left = mp[y];
        }
        else{
            mp[x]->right = mp[y];
        }
    }
    cout << getWidth(root) << endl;
    return 0;
}