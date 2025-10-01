#include <iostream>
#include <vector>
using namespace std;

void subbarray(int k, vector<int> a){
    int start = -1;
    int end = 0;
    int sum = a[end];
    int res = a.size();
    while(end < a.size()){
        if(sum >= k){
            if(res > end - start + 1){
                res = end - start + 1;
            }
            sum -= a[start];
            start++;
        }
        else{
            end++;
            sum += a[end];
        }
    }
    cout << res << endl;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    subbarray(k, a);
    return 0;
}