#include <iostream>
#include <vector>
using namespace std;

int subbarays(const vector<int>& a, int x){
    int n = a.size();
    int count = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + a[i] > x){
            sum = a[i];
            count++;
        } else {
            sum += a[i];
        }
    }
    return count;
}

void binsearch(const vector<int> &a, int maxElem, int k, int summa){
    int left = maxElem;
    int right = summa;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(subbarays(a, mid) <= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    int maxElem = 0;
    int summa = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxElem) maxElem = a[i];
        summa += a[i];
    }
    binsearch(a, maxElem, k, summa);
    return 0;
}