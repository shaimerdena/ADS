#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int>> &vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> L(n1), R(n2);

    for(int i=0; i<n1; i++) L[i] = vec[left + i];
    for(int i=0; i<n2; i++) R[i] = vec[mid + i + 1];

    int i=0, j=0, k=left;

    while(i < n1 && j < n2){

        int sum1 = 0;
        for(int x : L[i]) sum1 += x;
        int sum2 = 0;
        for(int x : R[j]) sum2 += x;

        if(sum1 == sum2){
            int w = 0;
            while(w < L[i].size() && w < R[j].size()){
                if(L[i][w] != R[j][w]){
                    if(L[i][w] < R[j][w]){
                        vec[k] = L[i];
                        i++;
                        break;
                    }
                    else{
                        vec[k] = R[j];
                        j++;
                        break;
                    }
                }
                w++;
            }
            if (w == L[i].size() || w == R[j].size()) {
                vec[k] = L[i];
                i++;
            }
        }
        else if(sum1 < sum2){
            vec[k] = R[j];
            j++;
        }
        else{
            vec[k] = L[i];
            i++;
        }
        k++;
    }
    while (i < n1) vec[k++] = L[i++];
    while (j < n2) vec[k++] = R[j++];
}

void merge_sort(vector<vector<int>> &vec, int left, int right){
    if(left >= right) return;

    int mid = left + (right - left)/2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

int main(){
    int n, m;
    cin >> n >>m;
    
    vector<vector<int>> vec(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
        }
    }
    merge_sort(vec, 0, vec.size() - 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}   