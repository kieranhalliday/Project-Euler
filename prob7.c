#include <stdio.h>

int main (void){
	int counter=2;
	int index=0;
	int a[10002]={0};

	while(a[10001]==0){
		if(check_prime(counter)==1){
			a[index]=counter;
			index++;
		}
		counter++;
	}
	
	printf("%d\n",a[10000]);
}

int check_prime(int counter){
	int i;

	for(i=counter/2; i>1; i--){
		if(counter%i==0)
			return 0;
	}
	return 1;
}
