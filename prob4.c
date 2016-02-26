#include <stdio.h>

int main (void){

int num1=999;
int num2=999;



while(num1-->800){
	while(num2-->800){
		if(check(num1*num2)==1){
			printf("%d,%d",num1,num2);
			num1=799;
			num2=799;
		}
	}
	num2=999;
}

return 0;
}

int check(long num){

int a,b,c,d,e,f;
f=num%10;
e=(num%100-f)/10;
d=(num%1000-e)/100;
c=(num%10000-d)/1000;
b=(num%100000-c)/10000;
a=(num%1000000-b)/100000;

if(a==f && b==e &&c==d)
return 1;

return 0; 
}



