//  Created by Kieran Halliday on 2018-06-05.
//  Copyright © 2018 Kieran Halliday. All rights reserved.
//
//The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
//
//We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
//
//There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
//
//If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

int main(int argc, const char * argv[]) {

	for(int numerator=10;numerator<MAX;numerator++){
		for(int denominator=numerator+1;denominator<MAX;denominator++){
			// Ignore trivial cases, non-trivial cases cannot be multiples of 10
			if(numerator % 10 != 0 && denominator % 10 != 0){
				string num_string = to_string(numerator);
				string denom_string = to_string(denominator);
				
				if(num_string.find(denom_string[0]) != string::npos){
					num_string.replace(num_string.find(denom_string[0]),1, "");
					denom_string.replace(0, 1, "");
				}else if(num_string.find(denom_string[1]) != string::npos){
					num_string.replace(num_string.find(denom_string[1]),1, "");
					denom_string.replace(1, 1, "");
				}
				
				// Numerator must be less than denominator
				double singleDigitNumerator = stod(num_string);
				double singleDigitDenom = stod(denom_string);
				
				if(singleDigitNumerator < singleDigitDenom && num_string.length()==1){
					if(singleDigitNumerator/singleDigitDenom == (double) numerator/ (double) denominator){
						cout <<numerator<< " " << denominator << endl;
					}
				}
			}
		}
	}
	return 0;
}
