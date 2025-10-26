#include <iostream>
#include <vector>
using namespace std;

//last_smaller_equal

int last_smaller_equal(vector<int> &vec, int target){
    int low = 0;
    int high = vec.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(vec[mid] <= target){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
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
    int target;
    cin >> target;

    cout << last_smaller_equal(vec, target) << endl;
    return 0;
}