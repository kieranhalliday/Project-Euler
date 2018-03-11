//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_ROWS = 1001, NUM_COLS = 1001;
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int howManyBlankSquaresBesideMe(vector< vector<int> > &grid, int row, int col){
	
	int retVal = 0;
	if(row+1 >= NUM_ROWS || col+1 >= NUM_COLS)
	// This means we are on the outer range of the sqaure and the missing sides must be blank
		return 3;

	if(grid[row+1][col] == 0) retVal++;
	if(grid[row-1][col] == 0) retVal++;
	if(grid[row][col+1] == 0) retVal++;
	if(grid[row][col-1] == 0) retVal++;
	
	
	return retVal;
}

// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
void p28() {
	int counter = 1, sum = 0, nextDirection = RIGHT;
	
	// Initialize vector to all 0's
	vector< vector<int> > grid(NUM_ROWS, vector<int>(NUM_COLS,0));
	
	// Populate vector
	// Start in middle of the grid
	int row = NUM_ROWS/2, col = NUM_COLS/2;
	while((row < NUM_ROWS && row >= 0) && (col < NUM_COLS && col >= 0)){
		grid[row][col] = counter;
		
		// Find next direction
		// First square
		if(counter == 1 || counter == 7 || counter == 8 || counter == 9) nextDirection = RIGHT;
		else if(counter == 3 || counter == 4) nextDirection = LEFT;
		else if(counter == 5 || counter == 6) nextDirection = UP;
		else if(counter == 2 || counter == 10) nextDirection = DOWN;
		
		// After first square
		else if(row == 0) nextDirection = RIGHT;
		else if (col == 0) nextDirection = UP;
		else if(grid[row-1][col] != 0){
			//  direction is either left or down, unless it is the top right corner
			if(howManyBlankSquaresBesideMe(grid, row, col) >= 3){
				if(row < col) nextDirection = DOWN;
				if(row >= col) nextDirection = LEFT;
			}
		} else {
			// direction is either right or up or it is the top right corner square
			if(howManyBlankSquaresBesideMe(grid, row, col) >= 3 && row < col) nextDirection = DOWN;
			else if(row <= col) nextDirection = RIGHT;
			else if(row > col) nextDirection = UP;
		}
		
		if(nextDirection == UP) row--;
		else if(nextDirection == DOWN) row++;
		else if(nextDirection == LEFT) col--;
		else if(nextDirection == RIGHT) col++;
		
		counter++;
	}
    
	// Sum for the diagonals of a square
	for(int i=0;i<NUM_ROWS;i++){
		sum += grid[i][i];
		sum += grid[NUM_ROWS-1-i][i];
	}
	// Because center square got counter twice
	sum -= 1;
	
	cout << sum << endl;
}



int main(int argc, const char * argv[]) {
	p28();
	return 0;
}
