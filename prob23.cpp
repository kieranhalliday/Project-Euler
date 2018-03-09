//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

#include <iostream>
#include <vector>


// Find the sum of all positive integers that cannot be written as the sum of two abundant numbers
void p23() {
    unsigned long long  sum=0;
    vector<int> divisorsA, abundantNums,removedList;
    
    // All numbers above 28123 can be written as the sum of 2 abundant numbers. Given by problem
    int MAX = 28123;
    
    // Find all abundant numbers
    for(int i=1;i<MAX;i++){
        for (int j=1; j<=i/2; j++) {
            if(i%j==0){
                divisorsA.push_back(j);
            }
        }
        int checkPerfectNumberSum = 0;
        for(int k=0;k<divisorsA.size();k++){
            checkPerfectNumberSum += divisorsA[k];
        }
        if(checkPerfectNumberSum>i){
            abundantNums.push_back(i);
        }
        
        divisorsA.clear();
    }
    
    // Find sum of all numbers from 1 to MAX
    for(int m=1;m<=MAX;m++){
        sum += m;
    }
    
    cout << "Abundant num size: " << abundantNums.size() << endl;
    cout << "Beginning Sum: " <<  sum << endl;
    
    // Find all abundant numbers
    for(int n=0;n<abundantNums.size()-1;n++){
        for(int p=n;p<abundantNums.size();p++){
            int toBeRemoved = abundantNums[n] + abundantNums[p];
            
            removedList.push_back(toBeRemoved);
        }
    }
    
    // Remove duplicate abundant numbers
    sort(removedList.begin(),removedList.end());
    removedList.erase(unique(removedList.begin(), removedList.end()), removedList.end());

    
    // Remove sum of abundant numbers from sum of all numbers
    for(int i=0;i<removedList.size();i++){
        if(removedList[i] <= MAX){
            sum -= (removedList[i]);
        }
    }
    
    cout << sum << endl;
    
}

int main(int argc, const char * argv[]) {
    p23();
    return 0;
}
