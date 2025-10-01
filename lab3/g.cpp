#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int capacity(const vector<int> &a, int mid, int f){
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += ceil((double)a[i] / mid);
    }
    return sum <= f;
}

void binary_search(const vector<int> &a, int f, int max){
    int left = 1;
    int right = max;
    while(left < right){
        int mid = (left + right) / 2;
        if(capacity(a, mid, f)){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main(){
    int n, f;
    cin >> n >> f;
    vector<int> a(n);
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];    
        if(a[i] > max) max = a[i];
    }
    binary_search(a, f, max);
    return 0;
}