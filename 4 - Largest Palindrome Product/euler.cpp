#include <iostream>
#include <string> 



//Status: Done
//Answer: 906609

//First attempt:
// std::cout << 999*999 << std::endl;
// Reasoning - Find the largest product of two 3-digit numbers (998001), then give the largest palindrome smaller than 998001 as the answer (997799).
// This is incorrect, but it does give us an upper bound.

//Hypothesis - It would be fast to find all palindromes in the range, but it would be slow to find which of them is the product of two 3-digit numbers. So it looks like the naive approach is a solid one.

int main(){
    int largest = 0;
    int l_a = 0;
    int l_b = 0;
    for(int a = 100; a < 1000; a++){
        for(int b = 100; b < 1000; b++){
            //Generate all products of two 3-digit numbers
            std::string product = std::to_string(a * b);

            //Check to see whether or not it's a palindrome
            bool is_palindrome = true;
            while(product.size() > 1){
                if(product[0] != product[product.size() - 1]){
                    is_palindrome = false;
                    break;
                }
                product.erase(0, 1);
                product.pop_back();
            }

            if(is_palindrome && a * b > largest){
                largest = a * b;
                l_a = a;
                l_b = b;
            }
        }
    }

    
    std::cout << l_a << std::endl;
    std::cout << l_b << std::endl;
    std::cout << largest << std::endl;
    return 0;
}