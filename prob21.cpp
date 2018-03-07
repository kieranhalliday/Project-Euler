
//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Find the sum of all amicable numbers under 10 000
//Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
//If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
void p21() {
    int sumA=0,sumB=0, totalSum=0;
    vector<int> divisorsA(100),divisorsB(100),amicables;

    //Go through each n less than 10 000
    for (int i=1;i<10000; i++) {
        //Check each possible divisor of i
        for (int j=1; j<=i/2; j++) {
            if(i%j==0){
                divisorsA.push_back(j);
            }
        }
        //
        // Get d(i) = b = sumA
        for(int k=0;k<divisorsA.size();k++){
            sumA+=divisorsA[k];
        }
        
        
        // PART 2
        // Find d(b)
        for(int m=1;m<=sumA/2;m++){
            if(sumA%m==0){
                divisorsB.push_back(m);
            }
        }
        for(int k=0;k<divisorsB.size();k++){
            sumB+=divisorsB[k];
        }
        
        // Test if amicables
        if(sumA != sumB && sumB==i){
            amicables.push_back(sumA);
            amicables.push_back(sumB);
        }
        
        // reset
        divisorsA.clear();
        divisorsB.clear();
        sumA=0;
        sumB=0;
    }
    
    sort(amicables.begin(),amicables.end());
    amicables.erase(unique(amicables.begin(), amicables.end()), amicables.end());
    
    for(int i=0;i<amicables.size();i++){
        totalSum+=amicables[i];
    }
    cout << totalSum << endl;
}

int main(int argc, const char * argv[]) {
    p21();
    return 0;
}
