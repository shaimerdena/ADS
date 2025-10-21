#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<string> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for(int i=0; i<n1; i++){
        L[i] = arr[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i].length() <= R[j].length()){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<string> &vec, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) /2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);

        vector<string> words;
        string word;
        stringstream ss(line);

        while(ss >> word){
            words.push_back(word);
        }
        merge_sort(words, 0, words.size()-1);

        for(int j=0; j<words.size(); j++){
            cout << words[j] << " ";
        }
        cout << endl;
    }
    return 0;
}