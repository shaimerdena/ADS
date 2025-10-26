#include <iostream>
using namespace std;

void sorting(int arr[], int len){
    for(int i=0; i<len-1 ; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int poisk(int arr[], int len, int tar){
    int left = 0;
    int right = len-1;
    
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid] == tar){
            return mid;
        }
        else if(arr[mid] < tar){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    sorting(arr, len);

    int target;
    cin >> target;
   
    int res = poisk(arr, len, target);
    if(res == -1){
        cout << "there is no such number";
    }
    else{
        cout << "the index of the number: " << res;
    }
}
