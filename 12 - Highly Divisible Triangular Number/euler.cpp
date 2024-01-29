#include <iostream>
#include <vector>

//Status: WIP
//Answer: 

const int factor_count_threshold = 500;
const int num_tris_to_check = 10000;

std::vector<int> triangle_number_memoization{0, 1};

/*
    n is 1-indexed
        eg. n=1 returns 1, n=2 returns 3, n=3 return 6, etc.
*/
unsigned long long int get_nth_triangle_number(unsigned int n){
    //Base Case
    if(n < triangle_number_memoization.size()){
        return triangle_number_memoization[n];
    }
    
    
    triangle_number_memoization.push_back(n + get_nth_triangle_number(n - 1));

    return triangle_number_memoization[n];
}

/*
    Returns the number of factors for a given natural number
*/
int count_factors(unsigned long long int n){
    int factor_count = 0;
    for(unsigned long long int i = 1; i <= n; i++){
        if(n % i == 0){
            factor_count++;
        }
    }

    return factor_count;
}

int main(){
    int debug = 0;
    int debug2 = 0;
    int debug_factors = 0;
    for(int i = 1; i <= num_tris_to_check; i++){
        unsigned long long int tri = get_nth_triangle_number(i);
        debug = tri;
        int factors = count_factors(tri);
        if(factors > debug_factors || debug2 > tri % 1000000){
            if(factors > debug_factors){
                debug_factors = factors;
            }
            std::cout << ' ' << std::endl << tri << std::endl << factors << std::endl << debug_factors << std::endl;
        }
        debug2 = tri % 1000000;
        if(factors > factor_count_threshold){
            std::cout << tri << std::endl;
            break;
        }
    }

    std::cout << count_factors(debug) << std::endl;

    // for(unsigned int i = 1; i <= 10; i++){
    //     std::cout << get_nth_triangle_number(i) << std::endl;
    // }

    //Display triangle num memoization table
    // for(int i = 0; i < triangle_number_memoization.size(); i++){
    //     std::cout << triangle_number_memoization[i] << ' ';
    // }
    // std::cout << std::endl;
}