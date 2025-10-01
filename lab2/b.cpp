#include <iostream>
using namespace std;

struct ListNode{
    string val;
    ListNode *next;

    ListNode(string x) : val(x), next(nullptr) {}
    ListNode(string x, ListNode *nxt) : val(x), next(nxt) {}
};

void push_back(ListNode*& head, ListNode*& tail, string x){
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

void printing(ListNode*& head, int num){
    ListNode *curr = head;
    while(num > 0){
        cout << curr->val << " ";
        curr = curr->next;
        num--;
    }
}

int main(){
    int num_w, shift;
    cin >> num_w >> shift;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    
    for(int i=0; i<num_w; i++){
        string word;
        cin >> word;
        push_back(head, tail, word);
    }

    int count = 0;
    ListNode *curr = head;
    ListNode *newtail = head;

    while(curr->next != nullptr){
        if(shift -1 == count){
            newtail = curr;
        }
        curr = curr->next;
        count++;
    }
    curr->next = head;
    head = newtail->next;
    newtail->next = nullptr;

    printing(head, num_w);

    return 0;
}
