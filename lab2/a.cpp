#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }
    int k;
    cin >> k;
    int res = abs(arr[0] - k);
    int index = 0;
    for(int i=0; i<n; i++){
        arr[i] = abs(arr[i] - k);
        if(arr[i] < res){
            index = i;
            res = arr[i];
        }
    }
    cout << index << endl;
    return 0;
}