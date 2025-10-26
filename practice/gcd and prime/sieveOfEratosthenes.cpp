#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n){
    vector<int> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);
    return 0;
}