#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class minheap{
private:
    vector<long long> array;
    long long capacity;
public:
    long long size;

    minheap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }

    void heapify_down(int i){
        int smallest = i;
        int left_child = 2*i+1;
        int right_child = 2*i+2;

        if(left_child < size && array[smallest] > array[left_child]){
            smallest = left_child;
        }
        if(right_child < size && array[smallest] > array[right_child]){
            smallest = right_child;
        }
        if(smallest != i){
            swap(array[smallest], array[i]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i){
        if(i == 0) return;
        int parent = (i-1)/2;
        if(array[parent] > array[i]){
            swap(array[parent], array[i]);
            heapify_up(parent);
        }
    }

    void build_heap(vector<long long> &v){
        array = v;
        size = v.size();
        capacity = size;
        for(int i=(size-1)/2; i>=0; i--){
            heapify_down(i);
        }
    }

    void insert_node(long long value){
        if(size == capacity){
            capacity *= 2;
            array.resize(capacity);
        }
        array[size] = value;
        heapify_up(size);
        size++;
    }

    long long extract_min(){
        if(size <= 0) return 0;
        if(size == 1){
            size--;
            return array[0];
        }
        int root = array[0];
        array[0] = array[size-1];
        size--;
        heapify_down(0);
        return root;
    }

    long long summa(){
        long long summa = 0;
        if(size <= 0) return 0;
        while(size > 1){
            long long cur_sum = 0;
            long long val1 = extract_min();
            long long val2 = extract_min();
            cur_sum = val1 + val2;
            summa+=cur_sum;
            insert_node(cur_sum);
        }
        return summa;
    }

    long long peek(){
        if(size == 0) return 0;
        return array[0];
    }
};

int main(){
    long long q, k;
    cin >> q >> k;

    vector<long long> vec(k);
    minheap heap(k);
    heap.build_heap(vec);
    
    long long curr_sum = 0;
    for(int i=0; i<q; i++){
        string command;
        cin >> command;
        if(command == "print"){
            cout << curr_sum << endl;
        }
        else if(command == "insert"){
            long long value;
            cin >> value;
            if(heap.size == k){
                if(value > heap.peek()){
                    curr_sum -= heap.extract_min();
                    heap.insert_node(value);
                    curr_sum += value;
                }
            }
            else{
                heap.insert_node(value);
                curr_sum += value;
            }

        }
    }

    return 0;
}