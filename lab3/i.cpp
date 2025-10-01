#include <iostream>
#include <vector>
using namespace std;

string binary_search(const vector<int> & v, int start, int end, int x){
    while(start<=end){
        int mid = (start + end)/2;
        if(v[mid] == x){
            return "Yes";
        } 
        else if(v[mid] < x){
            start = mid + 1;
        }
        else if(v[mid] > x){
            end = mid - 1;
        }
    }
    return "No";
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        nums[i] = x;
    }
    int target;
    cin >> target;
    int start = 0;
    int end = n-1;
    cout << binary_search(nums, start, end, target) << endl;
    return 0;
}