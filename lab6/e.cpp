#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] >= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}
 
void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
        }
    }
    for(int j=0; j<m; j++){
        vector<int> column;
        for(int i=0; i<n; i++){
            column.push_back(vec[i][j]);
        } 
        quickSort(column, 0, n-1);

        for(int i=0; i<n; i++){
            vec[i][j] = column[i];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}