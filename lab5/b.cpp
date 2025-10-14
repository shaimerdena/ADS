#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap{
private:
    vector<int> array;
    int capacity;

public:
    int size;
    
    MaxHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }

    void heapify_down(int i){
        int biggest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < size && array[left] > array[biggest]){
            biggest = left;
        }
        if(right < size && array[right] > array[biggest]){
            biggest = right;
        }
        if(biggest != i){
            swap(array[biggest], array[i]);
            heapify_down(biggest);
        }
    }

    void heapify_up(int i){
        if(size == 0) return;
        int parent = (i - 1)/2;
        if(array[parent] < array[i]){
            swap(array[parent], array[i]);
            heapify_up(parent);
        }
    }

    void BuildHeap(vector<int> &arr){
        array = arr;
        size = arr.size();
        capacity = size;
        for(int i = (size - 1)/2; i>=0; i--){
            heapify_down(i);
        }
    }

    void InsertNode(int value){
        if(size == capacity){
            capacity *= 2;
            array.resize(capacity);
        }
        size++;
        array[size-1] = value;
        heapify_up(size-1);
    }

    int peek(){
        if(size <= 0){
            return -1;
        }
        return array[0];
    }

    int ExtractMax(){
        if(size <= 0){
            return -1;
        }
        if(size == 1){
            size--;
            return array[0];
        }
        int root = array[0];
        array[0] = array[size -1];
        size--;

        heapify_down(0);
        return root;
    }

};

int main(){
    int n;
    cin >> n;
    MaxHeap maxheap(n);
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    maxheap.BuildHeap(arr);

    while(maxheap.size > 1){
        int val1 = maxheap.ExtractMax();
        int val2 = maxheap.ExtractMax();
        if(val1 > val2){
            int new_node = val1 - val2;
            maxheap.InsertNode(new_node);
        }
    }
    if(maxheap.size == 0){
        cout << 0 << endl;
    }
    else if(maxheap.size == 1){
        cout << maxheap.peek() << endl;
    }

    return 0;
}