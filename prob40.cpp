//  Created by Kieran Halliday on 2018-06-05.
//  Copyright © 2018 Kieran Halliday. All rights reserved.
//
//An irrational decimal fraction is created by concatenating the positive integers:
//
//0.123456789101112131415161718192021...
//
//It can be seen that the 12th digit of the fractional part is 1.
//
//If dn represents the nth digit of the fractional part, find the value of the following expression.
//
//d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int MAX = 1000000;

int main(int argc, const char * argv[]) {

	int valueToAddNext = 0, digitIndex = 0, count = 0, product = 1;
	
	for(; digitIndex<=MAX; digitIndex+=to_string(valueToAddNext).length()){
		valueToAddNext++;

		if(digitIndex <= pow(10,count) && digitIndex+to_string(valueToAddNext).length() >= pow(10,count)){
			cout << to_string(valueToAddNext)[pow(10,count)-digitIndex-1] << endl;

			string s;
			s.push_back(to_string(valueToAddNext)[pow(10,count)-digitIndex-1]);
			product *= stoi(s);
			count++;
		}
	}
	cout << "Product: " << product << endl;
	return 0;
}
