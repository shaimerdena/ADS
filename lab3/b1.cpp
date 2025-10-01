#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int subarrays(const vector<ll>& a, ll x) {
    int cnt = 1;
    ll sum = 0;
    for (ll v : a) {
        if (sum + v > x) {
            sum = v;
            ++cnt;
        } else {
            sum += v;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll maxElem = 0;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxElem) maxElem = a[i];
        total += a[i];
    }

    ll left = maxElem;
    ll right = total;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (subarrays(a, mid) <= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << "\n";
    return 0;
}
