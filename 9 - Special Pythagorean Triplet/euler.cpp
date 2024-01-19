#include <iostream>

//Status: Done
//Answer: 31875000


int main(){
    //Find every combination of a, b, and c that sums to 1000
    for(int a = 1; a < 1000; a++){
        for(int b = 1; b < 1000; b++){
            int c = 1000 - a - b;

            //If it's our triple, we're done
            if(a * a + b * b == c * c){
                std::cout << a << ", " << b << ", " << c << std::endl;
                std::cout << a * b * c << std::endl;
                return 0;
            }
        }
    } 
}