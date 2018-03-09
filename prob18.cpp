#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void Q18(){
	printf("Starting Q18\n");
	
	int triangle[120]={75,95, 64,17, 47, 82,18, 35, 87, 10,20, 04, 82, 47, 65,19, 01, 23, 75, 03, 34,88, 02, 77, 73, 07, 63, 67,99, 65, 04, 28, 06, 16, 70, 92,41, 41, 26, 56, 83, 40, 80, 70, 33,41, 48, 72, 33, 47, 32, 37, 16, 94, 29,53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
	int starting_index;
	
	//Start from the bottom row and move upwards, replacing the next
	//row up with the highest cost to get there. The rows are different lengths,
	//ranging from 1 to 15
	for(int i=15;i>1;i--){
		for(int j=0;j<i;j++){
			starting_index=0;
			for(int m=15;m>=i;m--){
				starting_index+=m;
			}
			if(triangle[120-starting_index+j]>triangle[120-starting_index+j+1]){
				triangle[120-starting_index-(i-1)+j]+=triangle[120-starting_index+j];
			}else{
				triangle[120-starting_index-(i-1)+j]+=triangle[120-starting_index+j+1];
			}
		}
	}
	printf("Longest Path: %d\n", triangle[0]);
}

int main(){
    Q18();

    return 0;
}

