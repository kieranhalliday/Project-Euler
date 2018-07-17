//  Created by Kieran Halliday on 2018-07-16.
//  Copyright © 2018 Kieran Halliday. All rights reserved.

#include <iostream>
#include <fstream>

using namespace std;

//This level is about unscrambling words.
//
//Find the original (unscrambled) words, which were randomly taken from a wordlist.<--
//Send a comma separated list of the original words, in the same order as in the list below.
//
//
//You have 30 seconds time to send the solution.

int main(int argc, const char * argv[]) {
	fstream input;
	string line, fileName = "wordlist.txt";
	
	input.open(fileName);
	
	// Count starts at one because first argument is program name
	for(int count = 1;count<argc;count++){
		while(getline(input, line)){
			bool isMatch = true;
			
			// remove \r from lines of wordlist. They appear after calling getline for this file
			line = line.substr(0,line.length()-1);
			string name = argv[count],lineHolder = line;

			if(name.length()!=lineHolder.length())
				isMatch = false;

			// Iterate through each letter and remove matching letters from both words
			for(int i=0;i<lineHolder.length();i++){
				if(name.find(lineHolder[i]) == string::npos){
					isMatch = false;
					break;
				}
				else{
					// Remove matching letters from both words
					name.replace(name.find(lineHolder[i]), 1, "");
					lineHolder.replace(lineHolder.find(lineHolder[i]),1, "");
					// Reset to 0 to avoid out of index error in next if statement
					i=0;
				}
				
				if(lineHolder.find(name[i]) == string::npos){
					isMatch = false;
					break;
				}
				else{
					// Remove matching letters from both words
					lineHolder.replace(lineHolder.find(name[i]),1, "");
					name.replace(name.find(name[i]),1, "");
				}
				
				// Break if the words are ever the same
				if(lineHolder.size()==1){
					if(lineHolder!=name) isMatch = false;
				}
			}
			if(isMatch)
				// Format answer string
				cout << line  << ",";
		}
		input.close();
		input.open(fileName);
	}
	input.close();
	return 0;
}
