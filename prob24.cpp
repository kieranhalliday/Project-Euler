//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

//A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
//
//012   021   102   120   201   210
//
//What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void p24() {
    // There are 9! permutations of the digits 1-9.
    // So, we know that 9! is less than 1 million and that the smallest 9! permutations have 0 as their first digit.
    // This means that 0 cannot be the first digit of the 1 millionth permutation.
    // This also means that the 1 millionth permutation is 10 digits long, or above 1 billion.
    // Since 9! is also less than half of 1 million, we know the first digit is not a 1 either.
    // Therefore you can start at index 2*9! and ignore all permutations that start with either 0 or 1.
    // This means that the 1 millionth permutation is above 2 billion, since it must have 10 digits and not start with a 0 or 1.
    // However, since 3*9! is above 1 million so we know that the 1 millionth permutation starts with a 2 since
    // all permutations in an ordered list with index 2*9!+1 to 3*9! must start with 2.
    
    vector<string> digits = {"0","1","2","3","4","5","6","7","8","9"};
    int index = 362880*2; // This is 9!*2
    long i;

    for(i=2000000000;index<1000000;i++){
        bool isPermutation = true;
        
        for(int j=0;j<digits.size();j++){
            // Make sure each digit is there
            string num = to_string(i);
            std::size_t found = num.find(digits[j]);
            if(found > digits.size()){
                isPermutation = false;
                break;
            }
        }

        if(isPermutation){
            cout << "Permutation Found: " << i << endl;
            index++;
        }
    }

    cout << "The 1 millionth permutation is: " << i-1 << endl;
}

int main(int argc, const char * argv[]) {
    p24();
    return 0;
}
