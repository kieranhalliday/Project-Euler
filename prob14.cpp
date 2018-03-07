#include <iostream>

using namespace std;

//Q14
// Which starting number,under one million,produces the longest Collatz chain?
void Q14(){
	printf("Starting Q14\n");
	
	long max=0,tempmax=0,counter,holder=0;
	
	for(int i=2;i<1000000;i++){
		counter=i;
		while(counter!=1){
			if(counter%2==0){
				counter = counter/2;
			}else{
				counter = (3*counter)+1;
			}
			tempmax++;
		}
		
		if(tempmax>max){
			max=tempmax;
			holder=i;
		}
		tempmax=0;
	}
	
	printf("Q14: %ld\n",holder);
}

int main(){
	Q14();
}
