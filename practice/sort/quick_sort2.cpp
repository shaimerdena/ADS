#include <iostream>

using namespace std;

int a[1000];

void quick_sort(int l, int r) {
    // Choose middle element as pivot
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;

    // Partition the array
    while (i < j) {
        // Find element on left that should be on right
        while (a[i] < p) i++;
        // Find element on right that should be on left
        while (a[j] > p) j--;

        // Swap elements if needed
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    // Recursively sort left partition
    if (l < j)
        quick_sort(l, j);
    // Recursively sort right partition
    if (i < r)
        quick_sort(i, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quick_sort(0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}