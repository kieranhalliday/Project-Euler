#include <stdio.h>
#include <stdlib.h>


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
