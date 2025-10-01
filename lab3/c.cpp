#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<m; i++){
        int count = 0;
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        for(int j=0; j<n; j++){
            if((v[j] >= l1 && v[j] <= r1) || (v[j] >= l2 && v[j] <= r2)){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}