#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int> &a, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] > target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int j, k;
    cin >> j >> k;
    vector<int> a(j * k);

    for (int i = 0; i < j * k; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int left = 0, right = j * k - 1;

    for (int x : v) {
        int idx = binary_search(a, left, right, x);
        if (idx == -1) {
            cout << -1 << endl;
        } else {
            int row = idx / k;
            int col;
            if (row % 2 == 0) col = idx % k;
            else col = k - 1 - (idx % k);
            cout << row << " " << col << endl;
        }
    }
    return 0;
}

