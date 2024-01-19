#include <iostream>

//Status: Done
//Answer: 6857

//This one is kind of ugly. The program eventually crashes (arithmetic exception on line 29), since i becomes an enourmous number. However, by the time it reaches that point, it's already found the largest prime factor of the target number.

bool is_prime(int n){
    //Disregard nonsense
    if(n <= 0){
        return false;
    }

    //False if something between 1 and n divides n
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }

    //Otherwise, it is prime
    return true;
}

int main(){
    int largest_prime_factor = 1;
    for(long i = 2; i < 300425737571; i++){
        //If this is a factor...
        if(600851475143 % i == 0){
            //...and it is prime
            if(is_prime(i)){
                largest_prime_factor = i;
                std::cout << i << std::endl;
            }
        }
    }
    std::cout << largest_prime_factor << std::endl;
}