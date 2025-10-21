#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {   
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
        quick_sort(vec, low, pi - 1);
        quick_sort(vec, pi + 1, high);
    }
}

int main(){
    string str;
    cin >> str;
    vector<int> vec;
    
    for(int i=0; i<str.length(); i++){
        vec.push_back(int(str[i]));
    }

    quick_sort(vec, 0, vec.size()-1);

    for(int i=0; i<vec.size(); i++){
        cout << char(vec[i]);
    }
    return 0;
}