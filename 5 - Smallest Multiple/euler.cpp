#include <iostream>


//Status: Done
//Answer: 232792560


int main(){
    int n = 1;
    while(true){
        bool this_is_the_one = true;
        for(int i = 1; i <= 20; i++){
            if(n % i != 0){
                this_is_the_one = false;
            }
        }
        if(this_is_the_one){
            std::cout << n << std::endl;
            return 0;
        }

        n++;
    }
}