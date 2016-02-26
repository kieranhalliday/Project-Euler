#include <stdio.h>
#include <stdlib.h>

int main (void){

int low=1;
int high=2;
int sum=0;
int temp;

while(low<4000000){
	if(low%2==0){
		sum+=low;
	}
	temp=high;
	high+=low;
	low=temp;
}
printf("%d\n",sum);
}
