#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    vector<long long> path;
    path.push_back(B);

    long long ops = 0;
    long long current = B;

    while(current > A) {
        if(current % 2 == 0) {
            current /= 2;
        } else {
            current += 1;
        }
        path.push_back(current);
        ops++;
    }

    while(current < A) {
        current += 1;
        path.push_back(current);
        ops++;
    }

    cout << ops << endl;
    for(long long i = path.size() - 2; i >= 0; i--) {
        cout << path[i] << " ";
    }

    return 0;
}


