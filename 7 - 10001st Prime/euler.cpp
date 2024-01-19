#include <iostream>

//Status: Done
//Answer: 104743

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

int main(){
    const int ordinal_prime_to_find = 10001;
    int nth_prime = 0;
    int num_primes_counted = 0;
    int n = 2;
    while(true){
        if(is_prime(n)){
            num_primes_counted++;

            if(num_primes_counted == ordinal_prime_to_find){
                nth_prime = n;
                break;
            }
        }

        n++;
    }

    std::cout << nth_prime << std::endl;
}