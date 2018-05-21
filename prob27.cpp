//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.

// Euler discovered the remarkable quadratic formula: n2+n+41
// It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39.
// However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is
// clearly divisible by 41.
// The incredible formula n2−79n+1601 was discovered, which produces 80 primes for the consecutive
// values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.
// Considering quadratics of the form: n2+an+b, where |a|<1000 and |b|≤1000
// where |n| is the modulus/absolute value of n
// e.g. |11|=11 and |−4|=4
// Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

const int MAX = 1000;
const int MIN = -999;

bool isPrime(int n) {
	if(n==1 || n == 0) return false;
	
	for(int i=2;i<=abs(n)/2;i++){
		if(abs(n)%i==0) return false;
	}
	return true;
}

int findSum(int n, int a, int b){
	return (n*n)+(a*n)+b;
}

void p27() {
	int maxConsecutivePrimes=0;
	int maxA=0,maxB=0;
	
	for(int a=MIN;a<MAX;a++){
		for(int b=MIN-1;b<=MAX;b++){
			int n=0;
			while(isPrime(findSum(n, a, b))){
				n++;
			}
			if(n>maxConsecutivePrimes){
				maxConsecutivePrimes=n;
				maxA = a;
				maxB = b;
			}
		}
	}
	cout << "MAX A: " << maxA << endl << "MAX B: " << maxB << endl;
}

int main(int argc, const char * argv[]) {
	p27();
	return 0;
}
