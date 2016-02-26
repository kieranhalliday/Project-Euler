#include <stdio.h>

int main (void){

long num=600851475143;
long counter=num/2+1;

printf("calculating\n");

while(--counter>0){

	if(num%counter==0 && check_prime(counter)==1)
		break;
}

printf("%ld\n",counter);



return 0;
}


int check_prime(long num){

//	long i;
//	for(i=1;i<=num/2;i++){
//		if(num%i==0)
//		return 0;
//	}

//	return 1;

if (num == 2) return 1;
else if (num % 2 == 0) return 0;
long i;
for (i = 3; i <= num/2; i += 2) {
    if (num%i==0) return 0;
}

return 1;


}
