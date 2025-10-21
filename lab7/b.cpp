#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec1, vector<int> &vec2){
    vector<int> new_vec(vec1.size() + vec2.size());

    int i=0, j=0, k=0;
    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] <= vec2[j]){
            new_vec[k] = vec1[i];
            i++;
        }
        else{
            new_vec[k] = vec2[j];
            j++;
        }
        k++;
    }

    while(i < vec1.size()){
        new_vec[k] = vec1[i];
        i++;
        k++;
    }

    while(j < vec2.size()){
        new_vec[k] = vec2[j];
        j++;
        k++;
    }

    for(int i=0; i<vec1.size()+vec2.size(); i++){
        cout << new_vec[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vec1(n);
    
    for(int i=0; i<n; i++){
        cin >> vec1[i];
    }

    int m;
    cin >> m;
    vector<int> vec2(m);

    for(int i=0; i<m; i++){
        cin >> vec2[i];
    }

    merge(vec1, vec2);

    return 0;
}