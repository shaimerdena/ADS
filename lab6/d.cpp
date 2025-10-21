#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
//gonna use heap sort just for fun

struct Date{
    int d, m, y;
};

bool operator<(const Date &a, const Date &b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

bool operator>(const Date &a, const Date &b) {
    return b < a;
}

class minHeap{
private:
    int capacity;
    vector<Date> array;

public: 
    int size;

    minHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }

    void heapify_down(int i){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

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

    void heapify_up(int i){
        if(i == 0) return;
        int parent = (i-1)/2;
        if(array[parent] > array[i]){
            swap(array[parent], array[i]);
            heapify_up(parent);
        }
    }

    void build_up(vector<Date> &vec){
        array = vec;
        size = vec.size();
        capacity = size;
        for(int i=(size - 1)/2; i>=0; i--){
            heapify_down(i);
        }
    }

    void extract_min(){
        if(size <= 0) return;
        else if(size == 1){
            size--;
            cout << setw(2) << setfill('0') << array[0].d << "-"
             << setw(2) << setfill('0') << array[0].m << "-"
             << array[0].y << endl;
            return;
        }
        Date root = array[0];
        array[0] = array[size - 1];
        size--;
        cout << setw(2) << setfill('0') << root.d << "-"
             << setw(2) << setfill('0') << root.m << "-"
             << root.y << endl;
        heapify_down(0);
    }

    void sorting(){
        while(size > 0){
            extract_min();
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<Date> dates(n);

    for(int i=0; i<n; i++){
        char dash;
        cin >> dates[i].d >> dash >> dates[i].m >> dash >> dates[i].y;
    }

    minHeap heap(n);
    heap.build_up(dates);
    heap.sorting();

    return 0;
}