#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Q16
// Sum of the digits of 2^1000
void Q16(){
	printf("Starting Q16\n");
	
	double exp = pow(2,1000);
	int size = 302,i=0,sum=0;
	char buffer[size];
	
	sprintf(buffer,"%.0f",exp);
	
	while(i<size){
		sum = sum + (int)buffer[i]-48;
		i++;
	}
	printf("\nSum: %d\n",sum);
	return;
}

int main() {
  Q16();
  return 0;
}
