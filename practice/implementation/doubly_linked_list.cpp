#include <iostream>
using namespace std;

struct dnode{
    int key;
    dnode *next;
    dnode *prev;

    dnode(int value) : key(value), next(nullptr), prev(nullptr){}
    dnode(int value, dnode *nxt, dnode *prv) : key(value), next(nxt), prev(prv){}
};

void push_back(dnode *&head, dnode *& tail, int val){
    dnode *curr = new dnode(val);
    if(head == nullptr){
        head = tail = curr;
    }
    else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

void push_front(dnode *&head, dnode *& tail, int val){
    dnode *curr = new dnode(val);
    if(head == nullptr){
        head = tail = curr;
    } else{
        curr->next = head;
        head->prev = curr;
        head = curr;
    }
}

void pop_back(dnode *& head, dnode *& tail){
    if(head!=nullptr){
        dnode *tmp = tail;
        tail = tail->prev;
        if(tail == nullptr){
            head = nullptr;
        }
        else{
            tail->next = nullptr;
        }
        delete tmp;
    }
}

void pop_front(dnode *& head, dnode *& tail){
    if(head!=nullptr){
        dnode *tmp = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        else{
            head->prev = nullptr;
        }
        delete tmp;
    }
}

int main(){
    int n;
    cin >> n;

    dnode *head = nullptr;
    dnode *tail = nullptr;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        push_back(head, tail, x);
    }
    pop_back(head, tail);
    pop_front(head, tail);

    dnode *curr = head;
    while(curr!=nullptr){
        cout << curr->key << " ";
        curr = curr->next;
    }

    return 0;
}