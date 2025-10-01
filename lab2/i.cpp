#include <iostream>
using namespace std;

struct DListNode{
    string val;
    DListNode *next;
    DListNode *prev;

    DListNode(string x) : val(x), next(nullptr), prev(nullptr){}
    DListNode(string x, DListNode *nxt, DListNode *prv) : val(x), next(nxt), prev(prv){}
};

void add_back(DListNode *&head, DListNode *&tail, string val){
    DListNode *node = new DListNode(val);
    if(head == nullptr){
        head = tail = node;
    }
    else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cout << "ok" << endl;
}

void add_front(DListNode *& head, DListNode *& tail, string val){
    DListNode *node = new DListNode(val);
    if(head==nullptr){
        head = tail = node;
    }
    else{
        node->next = head;
        head->prev = node;
        head = node;
    }
    cout << "ok" << endl;
}

void erase_front(DListNode *& head, DListNode *& tail){
    if(head!=nullptr){
        DListNode *tmp = head;
        cout << head->val << endl;
        head = head->next;
        if(head!=nullptr){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        delete tmp;
    }else{
        cout << "error" << endl;
    }
}

void erase_back(DListNode *&head, DListNode *& tail){
    if(tail!=nullptr){
        DListNode *tmp = tail;
        cout << tail->val << endl;
        tail = tail->prev;
        if(tail!=nullptr){
            tail->next = nullptr;
        }
        else{
            head = nullptr;
        }
        delete tmp;
    }
    else{
        cout << "error" << endl;
    }
}

string front(DListNode *&head){
    if(head!=nullptr){
        return head->val;
    }
    else{
        return "error";
    }
}

string back(DListNode *&tail){
    if(tail!=nullptr){
        return tail->val;
    }
    else{
        return "error";
    }
}

void clear(DListNode *&head, DListNode *& tail){
    while(head!=nullptr){
        DListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    cout << "ok" << endl;
}

int main(){
    DListNode *head = nullptr;
    DListNode *tail = nullptr;

    string val;
    string x;
    while(cin >> val && val!="exit"){
        if(val == "add_front"){
            cin >> x;
            add_front(head, tail, x);
        }
        else if(val == "add_back"){
            cin >> x;
            add_back(head, tail, x);
        }
        else if(val == "erase_front"){
            erase_front(head, tail);
        }
        else if(val == "erase_back"){
            erase_back(head, tail);
        }
        else if(val == "front"){
            cout << front(head) << endl;
        }
        else if(val == "back"){
            cout << back(tail) << endl;
        }
        else if(val == "clear"){
            clear(head, tail);
        }
    }
    cout << "goodbye" << endl;
}