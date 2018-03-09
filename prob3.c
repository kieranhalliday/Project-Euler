#include <stdio.h>

//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

int main (void){
	const long num = 600851475143;
	long counter=num/2+1;

	while(--counter>0){

		if(num%counter==0 && check_prime(counter)==1)
			break;
	}

	printf("%ld\n",counter);

	return 0;
}


int check_prime(long num){
	long i;
	
	if (num == 2) return 1;
	else if (num % 2 == 0) return 0;

	for (i = 3; i <= num/2; i += 2) {
    		if (num%i==0) return 0;
	}

	return 1;
}
