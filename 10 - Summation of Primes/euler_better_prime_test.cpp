#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

//Status: Done
//Answer: 142913828922

//Postmortem: The performance issue was definitely the poor initial primality test. Multithreading had a ~40% increase in performance over the most naive implementation, but
//  was still nowhere near optimized (1.5 mins to reach 200k numbers checked). Implementing the better prime test on this had literally no change. Implementing the better
//  prime test on the original, naive-looking code brought the performance up by several orders of magnitude, and was the final implementation used in this project.

const int primes_below = 2000000;   //The number for which we are trying to find the sum of all lesser primes


std::vector<int> prime_memoization_table = {2};
bool build_prime_list(int n){
    //Edge case checks
    if(n < 2){
        return false;
    }

    if(n == 2){
        return true;
    }

    //Actual prime test (technically a composite test)
    for(int i = 0; i < prime_memoization_table.size(); i++){
        if(n % prime_memoization_table[i] == 0){
            return false;
        }
    }

    //If not composite, it's a prime
    prime_memoization_table.push_back(n);
    return true;
}


int main(){
    //Edge cases
    if(primes_below < 2){
        return 0;
    }
    
    long long int sum = 2;

    if(primes_below == 2){
        sum = 0;
    }

    //Begin finding primes
    int debug = 0;
    for(int i = 3; i < primes_below; i += 2){
        build_prime_list(i);
    }

    sum = 0;
    for(int i = 0; i < prime_memoization_table.size(); i++){
        sum += prime_memoization_table[i];
    }

    //Display the answer
    std::cout << sum << std::endl;
}