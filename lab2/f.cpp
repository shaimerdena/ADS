#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt){}
};

void push_back(ListNode *& head, ListNode *& tail, int x){
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

void adding_an_elem(ListNode *&head, int index, int target){
    ListNode *curr = head;
    ListNode *node = new ListNode(target);
    ListNode *continuation;
    if(index > 0){
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        continuation = curr->next;
        curr->next = node;
        node->next = continuation;
    }
    else{
        continuation = head;
        head = node;
        node->next = continuation;
    }
}

void printing(ListNode *& head){
    ListNode *curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}

int main(){
    int num;
    cin >> num;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for(int i=0; i<num;i++){
        int x;
        cin >> x;
        push_back(head, tail, x);
    }
    int target;
    cin >> target;
    int index;
    cin >> index;

    adding_an_elem(head, index, target);
    printing(head);

    return 0;
}