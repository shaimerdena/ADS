#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    Node *curr = head;
    if(head == nullptr || p==0){
        node->next = head;
        return node;
    }
    for(int i=0; i<p-1; i++){
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    if(p == 0){
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    else{
        Node *curr = head;
        for(int i=0; i<p-1; i++){
            curr = curr->next;
        }
        Node *tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1 == 0){
        Node *tmp = head;
        head = head->next;
        tmp->next= nullptr;
        head = insert(head, tmp, p2);
        return head;
    }
    else{
        Node *curr = head;
        for(int i=0; i<p1-1; i++){
            curr = curr->next;
        }
        Node *tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = nullptr;
        head = insert(head, tmp, p2);
        return head;
    }
}
 
Node* reverse(Node* head){
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
void print(Node* head){
    if(head == nullptr){
        cout << -1 << endl;
    }
    else{
        Node *curr = head;
        while(curr != nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    if(head == nullptr || head->next == nullptr || x==0) return head;
    Node *tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = head;

    Node *curr = head;
    for(int i=0; i<x-1; i++){
        curr = curr->next;
    }
    Node *newhead = curr->next;
    curr->next = nullptr;
    return newhead;
}
 
Node* cyclic_right(Node* head, int x){
    if(head == nullptr || head->next == nullptr || x==0) return head;
    Node *tail = head;
    int size = 1;
    while(tail->next != nullptr){
        tail = tail->next;
        size++;
    }
    tail->next = head;

    Node *curr = head;
    for(int i=0; i<size-x-1; i++){
        curr = curr->next;
    }
    Node *newhead = curr->next;
    curr->next = nullptr;
    return newhead;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}