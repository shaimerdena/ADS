#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int capacity(vector<int> &a, int x){
    int summa =0;
    for(int i = 0; i < a.size(); i++){
        summa += ceil((double)a[i]/x);
    }
    return summa;
}

void binary_search(int max, vector<int> &a, int k){
    int left = 1;
    int right = max;
    while(left < right){
        int mid = (left + right) / 2;
        if(capacity(a, mid) <= k){
            right = mid;
        } else {
            left = mid + 1;
        }
    }   
    cout << left << endl;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max) max = a[i];
    }

    binary_search(max, a, k);
    return 0;
}