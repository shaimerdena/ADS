#include <iostream>
#include <vector>
using namespace std;

int check(int a){
    if(a == 97 || a==101 || a==105 || a==111 || a==117){
        return 1;
    }
    else{
        return 0;
    }
}

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if ((check(vec[j]) == 1 && check(pivot) == 0) ||    
            (check(vec[j]) == check(pivot) && vec[j] <= pivot)) {   
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quick_sort(vector<int> &vec, int low, int high){
    if(low < high){
        int pi = partition(vec, low, high);
        quick_sort(vec, low, pi -1);
        quick_sort(vec, pi +1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        vec[i] = int(x);
    }
    quick_sort(vec, 0, vec.size()-1);
    for(int i=0; i<vec.size(); i++){
        cout << char(vec[i]);
    }
    return 0;
}