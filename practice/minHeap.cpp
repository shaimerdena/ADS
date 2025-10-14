#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
class MinHeap {

 private:
    vector<int> array;  
    int size;         
    int capacity;     
 public:
    MinHeap(int capacity) {
         this->size = 0;
         this->capacity = capacity;
         this->array.resize(capacity);
    }

    void heapify_down(int i) {
        int smallest = i;    
        int left = 2 * i + 1;    
        int right = 2 * i + 2;   
        if (left < size && array[left] < array[smallest])
            smallest = left;
        if (right < size && array[right] < array[smallest])
            smallest = right;
        if (smallest != i) {
            swap(array[i], array[smallest]);  
            heapify_down(smallest);                
        }
    }

    void build_heap(vector<int>& arr) {
        // Heapify the (n-1)/2 nodes
        for (int i = (arr.size() - 1) / 2; i >= 0; i--) {
            heapify_down(i);
        }
    }

    void insertNode(int value) {
        if (size == capacity) {
            capacity *= 2;
            array.resize(capacity);
        }
        size++;
        int i = size - 1;
        array[i] = value;
        while (i != 0 && array[(i - 1) / 2] > array[i]) {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int peek() {
            if (size <= 0)
                return -1;  // Indicates that the heap is empty
        return array[0];
        }

    int extractMin() {
            if (size <= 0)
                return -1;  // Indicates that the heap is empty
            if (size == 1) {
                size--;
                return array[0];
            }
            int root = array[0];
            array[0] = array[size - 1];
            size--;
            // Heapify the root node after deletion
            heapify_down(0);  
            return root;
        }

    void deleteNode(int key) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Key not found" << endl;
            return;
        }
        if (index == size - 1) {
                size--;
                return;
            }
        array[index] = array[size - 1];
            size--;
        heapify_down(index);
    }

// Function to print the values of  the  min heap

    void printHeap() const {
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap minHeap(6);
    vector<int> arr = {15, 10, 5, 4, 3, 2};
    minHeap.build_heap(arr);
    cout<<"Min Heap built from the array: ";
    minHeap.printHeap();
    minHeap.insertNode(1);
    cout << "Min Heap After inserting the node 1: ";
    minHeap.printHeap();
    cout << "Topmost value of min Heap: " << minHeap.peek() << endl;
    cout << "Minimum Extracted value fro Min Heap: " << minHeap.extractMin() << endl;
    cout << "After extracting Min Heap: ";
    minHeap.printHeap();
    minHeap.deleteNode(4);
    cout << "After deleting the node 4 from the Min Heap: ";
    minHeap.printHeap();
    return 0;
}