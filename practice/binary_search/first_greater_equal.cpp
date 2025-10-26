#include <iostream>
#include <vector>
using namespace std;

//first greater then >= x

int first_greater_than(vector<int> &v, int target){
    int low = 0;
    int high = v.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    int x;
    cin >> x;

    cout << first_greater_than(vec, x) << endl;

    return 0;
}