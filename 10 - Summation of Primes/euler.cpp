#include <iostream>

//Status: Failed due to performance issues (see euler_multithread.cpp)
//Answer: 


bool is_prime(int n){
    if(n < 2){
        return false;
    }

    if(n == 2){
        return true;
    }

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

const int primes_below = 2000000;

int main(){
    if(primes_below < 2){
        return 0;
    }
    
    int sum = 2;

    if(primes_below == 2){
        sum = 0;
    }

    int debug = 0;
    for(int i = 3; i < primes_below; i += 2){
        if(debug > i % 100000){
            std::cout << i << std::endl;
        }
        debug = i % 1000;
        if(is_prime(i)){
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}