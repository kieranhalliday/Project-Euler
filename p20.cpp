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

// Find the sum of the digits of 100!
void p20() {
    // Less than 200 digits in the number 100!
    const int MAX_SIZE = 200;
    
    vector<int> factorial(MAX_SIZE,0);
    
    factorial[0] = 1;
    int carry = 0;
    // From integers 2 to 100
    for(int i=2;i<=100;i++){
        // For indices 0 to MAX_SIZE-1
        for(int j=0;j<MAX_SIZE;j++){
            int sum = i*factorial[j];
            int secondSum = carry + sum;
            factorial[j] = secondSum % 10;
            carry = secondSum / 10;
        }
    }
    
    int sum =0;
    for(int i=0;i<MAX_SIZE;i++){
        sum +=factorial[i];
        cout << "Digit " << i << " : " << factorial[i] << endl;
    }
    
    cout << "Sum Final: " << sum << endl;
}

int main(int argc, const char * argv[]) {
    p20();
    return 0;
}
