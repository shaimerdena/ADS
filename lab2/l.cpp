# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }
};

int findMaxSum(int n, Node *head) {
  Node *curr = head->next;
  int summa = head->val;
  int max = head->val;
  while(curr != nullptr){
    if(summa + curr->val > curr->val){
      summa = curr->val + summa;
    }
    else{
      summa = curr->val;
    }
    if(max < summa){
      max = summa;
    }
    curr = curr->next;
  }
  return max;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
