#include <stdio.h>
#include <math.h>

/*


A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.


*/
int main (){
	int sum=1000;
	int a,b,c;

	for(a=1;a<500;a++){
		for(b=1;b<500;b++){
			if(check_square(a,b))
				printf("%d, %d\n",a,b);
		}
	}

	return 0;
}

int check_square(int a, int b){

	double at=pow(a,2);
	double bt=pow(b,2);
	double sqr = sqrt(at+bt);
	
	if(fmod(sqr,1)!=0)
		return 0;
	if(sqr+a+b==1000){
	printf("%lf\n",sqr);
	return 1;
	}
	return 0;
}
