#include <iostream>
#include <thread>
#include <vector>

//Status: Failed due to performance issues (see euler_better_prime_test.cpp)
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

void increment_sum_if_prime(int* sum, int n){
    if((n - 1) % 25000 == 0){
        std::cout << n << std::endl;
    }

    if(is_prime(n)){
        *sum += n;
    }
    return;
}

// const int primes_below = 10;
// const int primes_below = 10000;
const int primes_below = 2000000;

int main(){
    if(primes_below < 2){
        return 0;
    }
    
    int sum = 2;

    if(primes_below == 2){
        sum = 0;
    }

    //Begin multithreading
    std::vector<std::thread> thread_list;

    //Create the threads
    for(int i = 3; i < primes_below; i += 2){
        thread_list.push_back(std::thread(increment_sum_if_prime, &sum, i));
    }

    //Gather the threads back up
    for(int i = 0; i < thread_list.size(); i++){
        thread_list[i].join();
    }

    //Display the answer
    std::cout << sum << std::endl;
}