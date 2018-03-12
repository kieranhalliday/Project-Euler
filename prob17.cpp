//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

int letterMap[100];

const int lettersInOneHundred = 7;
const int lettersInOneThousand = 8;
const int lettersInAnd = 3;

int numLettersIn(int num) {
    int numLetters = 0;
    
    // Base case
    if(num<=10) return letterMap[num];
    
    // Count letters in 2 digit number
    if(num<100){
        if(num / 10 == 6 || num / 10 == 7 || num / 10 == 9){
            // Add 2 for the 'ty' like in sixty, then add the second digit's letters
            return letterMap[num/10] + 2 + numLettersIn(num%10);
        } else if(num>19){
            // Letter map holds the cases that are spelled different with the 'ty'.
            // For example, fifty does not contain five
            return letterMap[(num/10)*10] + numLettersIn(num%10);
        } else{
            // For the teens
            if(num == 11 || num == 12 || num == 13 || num == 15 || num == 18){
                return letterMap[num];
            } else{
                // Add 4 for the 'teen'
                return letterMap[num-10] + 4;
            }
        }
    }
    
    // Deal with the 100 digit
    if(num<1000) {
        if(num%100==0){
            numLetters += (lettersInOneHundred+numLettersIn(num/100));
        }else{
            numLetters += (lettersInOneHundred+lettersInAnd+numLettersIn(num/100)+numLettersIn(num%100));
        }
    }
    
    if(num>=1000) numLetters = letterMap[num/1000] + lettersInOneThousand;
    
    cout << "numLetters in "<< num << " is " << numLetters << endl;
    
    return numLetters;
}

void p17() {
    int numLettersUsed = 0;
    int start = 1, end = 1000;
    
    for(int i=start;i<=end;i++){
        numLettersUsed += numLettersIn(i);
    }
    
    cout << numLettersUsed << endl;
}

int main(int argc, const char * argv[]) {
    
    // Populate array with base values
    for(int i=0;i<100;i++){
        switch(i){
            case 1: letterMap[i]=3; break;
            case 2: letterMap[i]=3; break;
            case 3: letterMap[i]=5; break;
            case 4: letterMap[i]=4; break;
            case 5: letterMap[i]=4; break;
            case 6: letterMap[i]=3; break;
            case 7: letterMap[i]=5; break;
            case 8: letterMap[i]=5; break;
            case 9: letterMap[i]=4; break;
            case 10: letterMap[i]=3; break;
            case 11: letterMap[i]=6; break;
            case 12: letterMap[i]=6; break;
            case 13: letterMap[i]=8; break;
            case 15: letterMap[i]=7; break;
            case 18: letterMap[i] = 8; break;
            case 20: letterMap[i]=6; break;
            case 30: letterMap[i]=6; break;
            case 40: letterMap[i]=5; break;
            case 50: letterMap[i]=5; break;
            case 80: letterMap[i] = 6; break;
            default: letterMap[i]=0; break;
        }
    }
    p17();
    return 0;
}
