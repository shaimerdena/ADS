#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap{
private:
    vector<int> array;
    int capacity;

public:
    int size;

    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }

    void heapify_down(int i){
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < size && array[left] < array[smallest]){
            smallest = left;
        }
        if(right < size && array[right] < array[smallest]){
            smallest = right;
        }
        if(smallest != i){
            swap(array[smallest], array[i]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i) {
        if (i == 0) return;
        int parent = (i - 1) / 2;
        if (array[parent] > array[i]) {
            swap(array[parent], array[i]);
            heapify_up(parent); 
        }
    }

    void build_heap(vector<int>& arr) {
        array = arr;     
        size = arr.size();
        for (int i = (size - 1) / 2; i >= 0; i--) {
            heapify_down(i);
        }
    }

    void insertNode(int value) {
        if (size == capacity) {
            capacity *= 2;
            array.resize(capacity);
        }
        array[size] = value; 
        heapify_up(size);
        size++;
    }

    int peek() {
        if (size <= 0)
            return -1;  
        return array[0];
    }

    int extractMin() {
        if (size <= 0)
            return -1;  
        if (size == 1) {
            size--;
            return array[0];
        }
        int root = array[0];
        array[0] = array[size - 1];
        size--;

        heapify_down(0);  
        return root;
    }

};

int main(){
    int n, m;
    cin >> n >> m;
    MinHeap minheap(n);
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    minheap.build_heap(arr);

    int count = 0;
    while (minheap.size > 1 && minheap.peek() < m) {
        int val1 = minheap.extractMin();
        int val2 = minheap.extractMin();
        int new_val = val1 + 2 * val2;
        minheap.insertNode(new_val);
        count++;
    }

    if(minheap.peek() >= m){
        cout << count << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}