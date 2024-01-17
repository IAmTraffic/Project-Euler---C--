#include <iostream>

//Status: Done
//Answer: 4613732

int main(){
    int a = 1;
    int b = 2;

    int sum_of_even_fib_nums = b;

    while(true){
        //Increment Fibonacci
        int c = a + b;
        a = b;
        b = c;

        //We are only looking for a certain size of number
        if(c > 4000000){
            break;
        }

        //Increase sum if it is even
        if(c % 2 == 0){
            sum_of_even_fib_nums += c;
        }
    }

    std::cout << sum_of_even_fib_nums << std::endl;

    return 0;
}