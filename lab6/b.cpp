#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int low, int high){
    int pivot = vec[high];
    int i = low - 1;

    for(int j=low; j<=high - 1; j++){
        if(vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i+1;
}

void quick_sort(vector<int> &vec, int low, int high){
    if(low < high){
        int pi = partition(vec, low, high);
        quick_sort(vec, low, pi-1);
        quick_sort(vec, pi+1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> first(n);
    vector<int> second(m);

    for(int i=0; i<n; i++){
        cin >> first[i];
    }
    for(int i=0; i<m; i++){
        cin >> second[i];
    }
    if(n > 0 && m > 0){
        quick_sort(first, 0, n-1);
        quick_sort(second, 0, m-1);

        int i=0;
        int j=0;
        while(i < n && j < m){
            if(first[i] == second[j]){
                cout << first[i] << " ";
                i++;
                j++;
            }
            else if(first[i] < second[j]){
                i++;
            }
            else{
                j++;
            }
        }
    }
    return 0;
}