#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int can_catch(vector<int> &a, int mid){
    int count = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] <= mid){
            count++;
        }
    }
    return count;
}

void bin_search(vector<int> &a, int k){
    int left = 0;
    int right = *max_element(a.begin(), a.end());
    while(left <= right){
        int mid = (left + right) / 2;
        if(can_catch(a, mid) >= k){
            right = mid - 1; 
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
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int maxi = max(x2, y2);
        a[i] = maxi;
    }
    bin_search(a, k);
    return 0;
}