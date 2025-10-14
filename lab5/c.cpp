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
        int left_child = 2*i +1;
        int right_child = 2*i +2;

        if(left_child < size && array[biggest] < array[left_child]){
            biggest = left_child;
        }
        if(right_child < size && array[biggest] < array[right_child]){
            biggest = right_child;
        }
        if(biggest != i){
            swap(array[biggest], array[i]);
            heapify_down(biggest);
        }
    }

    void heapify_up(int i){
        if(i == 0) return;
        int parent = (i-1)/2;
        if(array[parent] < array[i]){
            swap(array[parent], array[i]);
            heapify_up(parent);
        }
    }

    void build_heap(vector<int> &v){
        array = v;
        size = v.size();
        capacity = size;
        for(int i=(size-1)/2; i >= 0; i--){
            heapify_down(i);
        }
    }

    void insert_node(int value){
        if(size == capacity){
            capacity *= 2;
            array.resize(capacity);
        }
        size++;
        array[size-1] = value;
        heapify_up(size-1);
    }

    int peek(){
        if(size == 0){
            return 0;
        }
        return array[0];
    }

    int extract_max(){
        if(size <= 0){
            return 0;
        }
        else if(size == 1){
            size--;
            return array[0];
        }
        int root = array[0];
        array[0] = array[size-1];
        size--;

        heapify_down(0);
        return root;
    }
};

int main(){
    int rows, people;
    cin >> rows >> people;

    MaxHeap seats(rows);
    vector<int> vec(rows);

    for(int i=0; i<rows; i++){
        cin >> vec[i];
    }

    seats.build_heap(vec);
    long long summa = 0;
    while(people>0){
        people--;
        summa += seats.peek();
        long long val = seats.extract_max();
        val--;
        if(val>0) seats.insert_node(val);
    }
    cout << summa << endl;
    return 0;
}