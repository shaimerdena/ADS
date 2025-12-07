 // утки и острова
#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> ducks(n);
    long long sum = 0, min_ducks = LLONG_MAX;

    for(int i = 0; i < n; i++) {
        cin >> ducks[i];
        sum += ducks[i];
        min_ducks = min(min_ducks, ducks[i]);
    } 

    long long total = sum + (n - 2) * min_ducks;

    cout << total;
}