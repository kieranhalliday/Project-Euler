#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Q15
//How many such routes are there through a 20×20 grid?
int Q15(int width,int height){
	printf("Starting Q15\n");
	
	unsigned long box[width][height];
	
	for(int i=0;i<width;i++){
		box[i][0]=1;
	}
	for(int j=0;j<height;j++){
		box[0][j]=1;
	}
	
	for(int k=1;k<width;k++){
		for(int m=1;m<height;m++){
			box[k][m]=box[k-1][m]+box[k][m-1];
		}
	}
	
	
	return box[width-1][height-1];
}


int main() {
  Q15(20,20);
  return 0;
}
