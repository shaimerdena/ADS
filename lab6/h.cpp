#include <iostream>
#include <vector>
using namespace std;

int upper_bound(vector<int> &vec, int target){
    int left = 0;
    int right = vec.size();
    while(left < right){
        int mid = (left + right)/2;
        if(vec[mid] <= target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        v[i] = int(x);
    }
    char x;
    cin >> x;

    int idx = upper_bound(v, x);

    cout << char(v[idx%n]);

    return 0;
}