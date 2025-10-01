#include <iostream>
#include <map>
using namespace std;

struct ListNode{
    char val;
    ListNode *next;

    ListNode(char x) : val(x), next(nullptr){}
    ListNode(char x, ListNode *nxt) : val(x), next(nxt) {}
};

void push_back(ListNode *&head, ListNode *& tail, char x){
    ListNode *node = new ListNode(x);
    if(head == nullptr){
        head = tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
}

void pop_front(ListNode *&head, ListNode *& tail){
    if(head!=nullptr){
        ListNode *tmp = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete tmp;
    }
}

void clear(ListNode *& head, ListNode *& tail){
    while(head != nullptr){
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

int main(){
    int n;
    cin >> n;
    while(n>0){
        map<char, int> freq;
        for(int i=97; i<=122; i++){
            freq.insert(make_pair(char(i), 0));
        }
        
        int c;
        cin >> c;

        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for(int i=0; i<c; i++){
            char x;
            cin >> x;
            freq[x]++;

            push_back(head, tail, x);

            if(freq[head->val] > 1){
                while(head != nullptr && freq[head->val] != 1){
                    pop_front(head,tail);
                }
            }
            if(head != nullptr){
                cout << head->val << " ";
            }
            else{
                cout << -1 << " ";
            }
        }
        cout << endl;
        clear(head, tail);
        --n;
    }
}
