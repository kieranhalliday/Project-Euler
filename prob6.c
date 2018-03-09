#include <stdio.h>

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

int main (void){

	int difference=s_of_squares(100)-s_of_sums(100);

	printf("%d\n",difference);

	return 0;
}



int s_of_squares(int max){
	int counter=1;
	int sum=0;

	for(counter;counter<=max;counter++){
		sum+=counter*counter;
	}

	return sum;
}

int s_of_sums(int max){
	int counter=1;
	int sum=0;

	for(counter;counter<=max;counter++){
		sum+=counter;
	}
	sum=sum*sum;
	return sum;
}
