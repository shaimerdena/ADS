#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    
    for(int i=0; i<n1; i++) L[i] = vec[left + i];
    for(int i=0; i<n2; i++) R[i] = vec[mid + i + 1];

    int i=0, j=0, k=left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            vec[k] = L[i];
            i++;
        }
        else{
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vec[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        vec[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &vec, int left, int right){
    if(left >= right) return;

    int mid = left + (right - left)/2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void find_common(vector<int> &vec1, vector<int> vec2){
    int i=0, j=0;
    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] == vec2[j]){
            cout << vec1[i] << " ";
            i++;
            j++;
        }
        else if(vec1[i] < vec2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> vec1(n);
    vector<int> vec2(m);

    for(int i=0; i<n; i++){
        cin >> vec1[i];
    }
    for(int i=0; i<m; i++){
        cin >> vec2[i];
    }

    merge_sort(vec1, 0, vec1.size()-1);
    merge_sort(vec2, 0, vec2.size()-1);
    find_common(vec1, vec2);

    return 0;
}