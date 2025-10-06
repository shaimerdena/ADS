#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void divide_and_conquer(vector<int> &v, int left, int right){
    if(left>right) return;
    int mid = (left + right)/2;
    cout << v[mid] << " ";
    
    divide_and_conquer(v, left, mid-1);
    divide_and_conquer(v, mid+1, right);
}

int main(){
    long double n;
    cin >> n;
    n = pow(2, n) - 1;
    vector<int> vr(n);
    for(int i=0; i<n; i++){
        cin >> vr[i];
    }
    sort(vr.begin(), vr.end());
    divide_and_conquer(vr, 0, vr.size()-1);
    return 0;
}