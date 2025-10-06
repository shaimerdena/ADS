#include <iostream>
using namespace std;

struct Node {
	int data;
    int count;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
        count = 1;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}else {
        root->count++;
    }
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
        if(root->count > 1){
            root->count--;
            return root;
        }
        else{
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->count = temp->count;
                temp->count = 1;
                root->right = deleteNode(root->right, temp->data);
                return root;
            }
        }
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int main(){
    int n;
    cin >> n;
    Node *root = nullptr;

    for(int i=0; i<n; i++){
        string command;
        int val;
        cin >> command >> val;
        if(command == "insert"){
            root = add(root, val);
        }
        else if(command == "cnt"){
            Node *found = find(root, val);
            if(found){
                cout << found->count << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(command == "delete"){
            root = deleteNode(root, val);
        }
    }
    return 0;
}