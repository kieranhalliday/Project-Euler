//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int howManyBlankSquaresBesideMe(vector< vector<int> > &grid, int row, int col){
    
    int retVal = 0;
    
    if(grid[row+1][col] == 0) retVal++;
    if(grid[row-1][col] == 0) retVal++;
    if(grid[row][col+1] == 0) retVal++;
    if(grid[row][col-1] == 0) retVal++;
    
    return retVal;
}

// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
void p28() {
    const int NUM_ROWS = 11, NUM_COLS = 11;
    const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
    
    int counter = 1;
    int nextDirection = RIGHT, lastDirection = -1;
    // Initialize vector to all 0's
    vector< vector<int> > grid(NUM_ROWS, vector<int>(NUM_COLS,0));
    
    // Populate vector
    // Start in middle of the grid
    int row = NUM_ROWS/2, col = NUM_COLS/2;
    while((row < NUM_ROWS && row >= 0) && (col < NUM_COLS && col >=0)){
        grid[row][col] = counter;
        
        // Find next direction
        // First square
        if(counter == 1 || counter == 7 || counter == 8 || counter == 9) nextDirection = RIGHT;
        else if(counter == 3 || counter == 4) nextDirection = LEFT;
        else if(counter == 5 || counter == 6) nextDirection = UP;
        else if(counter == 2 || counter == 10) nextDirection = DOWN;
        
        else if(grid[row-1][col] != 0){
            //  direction is either left or down
            if(howManyBlankSquaresBesideMe(grid, row, col) >= 3){
                //corner square
                if(row < col) nextDirection = DOWN;
                if(row > col) nextDirection = LEFT;
            }
        } else if(grid[row+1][col] != 0){
            // direction is either right or up
            if(row < col) nextDirection = RIGHT;
            if(row > col) nextDirection = UP;
        }
        
        if(nextDirection == UP) row--;
        else if(nextDirection == DOWN) row++;
        else if(nextDirection == LEFT) col--;
        else if(nextDirection == RIGHT) col++;
        
        counter++;
    }
    
    for(int i=0;i<NUM_ROWS;i++){
        for(int j=0;j<NUM_COLS;j++){
            cout << grid[i][j];
            
            // Evenly space the grid with 3 spaces
            for(int k=0;k<2;k++){
                cout << " ";
            }
            if(grid[i][j]<10) cout << " ";
        }
        cout << endl;
    }
}
               


int main(int argc, const char * argv[]) {
    p28();
    return 0;
}
