#include <iostream>
using namespace std;

struct ListNode{
        int val;
        ListNode* next;
        
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
    };

int main(){
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head ->next->next = new ListNode(3);

    ListNode *curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}