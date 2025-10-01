#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

void push_back(ListNode *& head, ListNode *& tail,int x){
    ListNode *node = new ListNode(x);

    if(head == nullptr){
        head = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
}

void delete_and_print(ListNode *&head){
    ListNode *curr = head;
    while(true){
        cout << curr->val << " ";
        if(curr->next != nullptr && curr->next->next != nullptr){
            curr = curr->next->next;
        }
        else{
            break;
        }
    }
}

int main(){
    int num;
    cin >> num;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for(int i=0; i<num; i++){
        int x;
        cin >> x;
        push_back(head, tail, x);
    }
    delete_and_print(head);
    return 0;
}