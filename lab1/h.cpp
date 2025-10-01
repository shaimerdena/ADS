#include <iostream>

int main(){
    bool flag = true;
    int num;
    std::cin >> num;
    if(num%2==0 && num>2){
        std:: cout << "NO" << std:: endl;
    }
    else if(num<2){
        std:: cout << "NO" << std:: endl;
    }
    else{
        for(int i=3; i * i<num; i+=2){
            if(num%i==0){
                flag = false;
                std:: cout << "NO" << std:: endl;
                break;
            }
        }
        if(flag == true){
            std:: cout << "YES" << std:: endl;
        }
    }
    return 0;
}