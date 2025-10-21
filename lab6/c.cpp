#include <iostream>
#include <vector>
using namespace std;
 
int partition(vector<long long> &vec, long long low, long long high) {
    long long pivot = vec[high];
    long long i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}
 
void quickSort(vector<long long> &vec, long long low, long long high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void check_for_difference(vector<long long> &vec){
    if (vec.size() < 2) return;
    long long min_diff = vec[1] - vec[0];
    for(int i=0; i<vec.size()-1; i++){
        if(vec[i+1] - vec[i] < min_diff){
            min_diff = vec[i+1] - vec[i];
        }
    }
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] == min_diff) {
            cout << vec[i] << " " << vec[i + 1] << " ";
        }
    }
}
 
int main() {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    quickSort(vec, 0, n-1);

    check_for_difference(vec);

    return 0;
}