#include <iostream>
using namespace std;

struct node{
    int key;
    node *next;

    node(int value) : key(value), next(nullptr){}
    node(int value, node *nxt) : key(value), next(nxt){}
};

void push_back(node *&head, node *& tail, int val){     //O(1)
    node *curr = new node(val);
    if(head == nullptr){
        head = tail = curr;
    }
    else{         
        tail->next = curr;
        tail = curr;
    }
}

void push_front(node *&head, node *& tail, int val){      //O(1)
    node *curr = new node(val);
    if(head == nullptr){
        head = tail = curr;
    } else{
        curr->next = head;
        head = curr;
    }
}

void pop_back(node *& head, node *& tail){   //O(n)
    if (head == nullptr) return; // empty
    if (head == tail) { // one elem
        delete head;
        head = tail = nullptr;
        return;
    }
    node *curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }
    delete tail;
    tail = curr;
    tail->next = nullptr;
}


void pop_front(node *& head, node *& tail){     //O(1)
    if(head != nullptr){
        node *tp = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete tp;
    }
}

int main(){
    int n;
    cin >> n;
    node *head = nullptr;
    node *tail = nullptr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        push_front(head, tail, x);
    }
    pop_back(head, tail);
    pop_front(head, tail);
    pop_back(head, tail);
    pop_back(head, tail);

    node *curr = head;
    while(curr != nullptr){
        cout << curr->key << " ";
        curr = curr->next;
    }
    return 0;
}