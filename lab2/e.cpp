#include <iostream>
using namespace std;

struct ListNode{
    string val;
    ListNode *next;

    ListNode(string x) : val(x), next(nullptr){}
    ListNode(string x, ListNode *nxt) : val(x), next(nxt){}
};

void push_front(ListNode *&head, string x){
    ListNode *node = new ListNode(x);
    node->next = head;
    head=node;
}

int duplicate(ListNode *&head, int count){
    ListNode *curr = head;
    ListNode *toDelete;
    while(curr!=nullptr && curr->next!=nullptr){
        if(curr->val == (curr->next)->val){
            toDelete = curr->next;
            curr->next = curr->next->next;
            count--;
            delete toDelete;
        }
        else{
            curr = curr->next;
        }
    }
    return count;
}

void printing(ListNode *& head){
    ListNode* curr = head;
    while(curr != nullptr){
        cout << curr->val << endl;
        curr = curr->next;
    }
}

int main(){
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        string x;
        cin >> x;
        push_front(head, x);
    }
    cout << "All in all: " <<  duplicate(head, num) << endl;
    cout << "Students: " << endl;
    printing(head);

    return 0;
}