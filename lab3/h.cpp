#include <iostream>
#include <vector>
using namespace std;

void binary_search(const vector<int> &a, int target){
    int left = 0;
    int right = a.size();
    while(left < right){
        int mid = (right + left) / 2;
        if(a[mid] < target){
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left+1 << endl;
}

int main(){
    int n, m;
    cin >> n >> m;

    int x;
    vector<int> v(n);
    int sum = 0;

    for(int i=0; i<n; i++){
        cin >> x;
        sum += x;
        v[i] = sum;
    }

    for(int i=0; i<m; i++){
        int target;
        cin >> target;
        binary_search(v, target);
    }
}