#include <stdio.h>
#include <stdlib.h>

// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

int main (void){
	const int MAX = 4000000
	int low=1, high=2,sum=0,temp;

	while(low < MAX){
		if(low % 2 == 0){
			sum+=low;
		}
		temp=high;
		high+=low;
		low=temp;
	}
	printf("%d\n",sum);
}
