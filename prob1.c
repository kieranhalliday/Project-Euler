#include <stdio.h>
#include <stdlib.h>

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
int main (void){
	int max=1000;
	int num=1;
	int sum=0;
	while(num<1000){
		if(num%3==0){
			sum=sum+num;
		}
		else if(num%5==0){
			sum=sum+num;
		}
	num++;
}

	printf("%d\n",sum);
}
