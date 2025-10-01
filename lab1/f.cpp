#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int index;
    cin >> index;

    int res = 2;
    int result;
    while(index > 0){
        if(isPrime(res)){
            index--;
            result = res;
        }
        res++;
    }
    cout << result << endl;
    return 0;
}
