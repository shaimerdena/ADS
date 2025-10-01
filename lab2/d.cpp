#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt){}
};

void push_back(ListNode *&head, ListNode *&tail, int x){
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

ListNode* merge_sort(ListNode * head){
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    while(fast->next!= nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;

    ListNode *left = merge_sort(head);
    ListNode *right = merge_sort(mid);

    ListNode dummy(0);
    ListNode *curr = &dummy;

    while(left!= nullptr && right!=nullptr){
        if(left->val < right->val){     //descending order
            curr->next = right;
            right = right->next;
        }
        else{
            curr->next = left;
            left = left->next;
        }
        curr = curr->next;
    }
    curr->next = (left != nullptr) ? left : right;

    return dummy.next;
}

void finding_mode(ListNode *& head){
    int count = 1;
    int max_count = 1;
    ListNode *curr = head;

    while(curr->next != nullptr){
        if(curr->val == curr->next->val){
            count++;
            if(count > max_count){ max_count = count;
            }
        }
        else{
            count = 1;
        }
        curr = curr->next;
    }
    curr = head;
    count = 1;
    while(curr->next != nullptr){
        if(curr->val == curr->next->val){
            count++;
        }
        else{
            if(max_count == count){
                cout << curr->val << " ";
            }
            count = 1;
        }
        curr = curr->next;
    }
    if(count == max_count){
        cout << curr->val << " ";
    }
}

int main(){
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        int x;
        cin >> x;
        push_back(head, tail, x);
    }
    head = merge_sort(head);
    finding_mode(head);

    return 0;
}