#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> array;
    int capacity;

    void heapify_down(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size() && array[left] > array[largest])
            largest = left;
        if (right < size() && array[right] > array[largest])
            largest = right;

        if (largest != i) {
            swap(array[i], array[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (array[i] > array[parent]) {
                swap(array[i], array[parent]);
                i = parent;
            } else break;
        }
    }

public:
    MaxHeap(int capacity = 10) : capacity(capacity) {
        array.reserve(capacity);
    }

    int size() const {
        return array.size();
    }

    bool empty() const {
        return array.empty();
    }

    void BuildHeap(const vector<int>& arr) {
        array = arr;
        capacity = max(capacity, (int)arr.size());
        for (int i = size() / 2 - 1; i >= 0; i--)
            heapify_down(i);
    }

    void InsertNode(int value) {
        if (size() == capacity) {
            capacity = max(1, capacity * 2);
            array.reserve(capacity);
        }
        array.push_back(value);
        heapify_up(size() - 1);
    }

    int peek() const {
        if (empty()) return -1;
        return array[0];
    }

    int ExtractMax() {
        if (empty()) return -1;

        int root = array[0];
        array[0] = array.back();
        array.pop_back();

        if (!empty()) heapify_down(0);
        return root;
    }

    void printHeap() const {
        for (int val : array)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    vector<int> nums = {3, 10, 5, 6, 2, 8};
    heap.BuildHeap(nums);

    cout << "Построенная куча: ";
    heap.printHeap();

    heap.InsertNode(15);
    cout << "После вставки 15: ";
    heap.printHeap();

    cout << "Максимум: " << heap.ExtractMax() << endl;
    cout << "После удаления максимума: ";
    heap.printHeap();
}
