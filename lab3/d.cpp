#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upper_bound(const vector<int> &v, int r){
    int right = v.size();
    int left = 0;
    while(left < right){
        int mid = (right + left) / 2;
        if(v[mid] <= r){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int lower_bound(const vector<int> &v, int l){
    int right = v.size();
    int left = 0;
    while(left < right){
        int mid = (right + left) / 2;
        if(v[mid] < l){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int counting(const vector<int> &v, int l, int r){
    return upper_bound(v, r) - lower_bound(v, l);
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i=0; i<q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1) {
            int cnt = counting(v, l1, r1) + counting(v, l2, r2);
            cout << cnt << "\n";
        } else {
            int cnt = counting(v, min(l1, l2), max(r1, r2));
            cout << cnt << "\n";
        }
    }    
    return 0;
}