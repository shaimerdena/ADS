#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int> &v, int power){
    int left = 0;
    int right = v.size()-1;
    int ans = -1; 
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] <= power){
            ans = mid;    
            left = mid + 1;  
        } else {
            right = mid - 1; 
        }
    }
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> summas(n);

    for(int i=0; i<n; i++){
        int x;
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += v[i];
        summas[i] = sum;
    }

    int powers;
    cin >> powers;
    for(int i=0; i<powers; i++){
        int power;
        cin >> power;
        
        int index = binary_search(v, power);

        if(index == -1){
            cout << 0 << " " << 0 << endl;
        } else {
            cout << index + 1 << " " << summas[index] << endl;
        }
    }
    return 0;
}