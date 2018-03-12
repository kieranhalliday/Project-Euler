//
//  main.cpp
//  Euler
//
//  Created by Halliday, Kieran on 2018-03-06.
//  Copyright © 2018 Halliday, Kieran. All rights reserved.
//

//Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
//begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
//multiply this value by its alphabetical position in the list to obtain a name score.

//For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
//is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

//What is the total of all the name scores in the file?

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Get score of a single name
int getScore(string name){
    int score = 0;
    
    for(int i=0;i<name.size();i++){
        // Char must be a capital letter in ASCII representation
        if((int)name[i] >=65 && (int)name[i]<=90){
            score+=((int)name[i])-64;
        }
    }
    return score;
}

// Used in quicksort
int myPartition(vector<string> &names, int lo, int hi){
    string pivot = names[lo];
    int i = lo;
    int j = hi;
    
    while(true){
        while(names[i].compare(pivot)<0){
            i++;
        }
        while(names[j].compare(pivot)>0){
            j--;
        }
        if(i>=j){
            return j;
        }
        
        // Swap names[i] and names[j]
        string temp = names[i];
        names[i] = names[j];
        names[j] = temp;
    }
}

void quickSort(vector<string> &names, int lo, int hi){
    // Generate random pivot
    if(lo<hi){
        int p = myPartition(names, lo, hi);
    
        // Sort lower side
        quickSort(names,lo,p);
        // Sort upper side
        quickSort(names,p+1,hi);
    }
}

void p22(){
    vector<string> names;
    ifstream inputFileName;
    unsigned long score = 0;
    
    inputFileName.open("p022_names.txt");
    
    if(inputFileName.is_open()){
        string text;
        string delimiter = ",";
        inputFileName >> text;
        
        // Iterate through while names still exist in the file
        string::iterator it = text.begin();
        string name;
        while(it != text.end()){
            name += *it;
            it++;
            if(name.find(delimiter) != string::npos){
                names.push_back(name);
                name = "";
            }
        }
        names.push_back(name);
        
        // Sort names in alphabetical order
        quickSort(names,0,names.size());
        
        // Count score
        for(int i=0;i<=names.size();i++){
            score += ((i) * getScore(names[i]));
        }
        cout << score << endl;
        inputFileName.close();
    }
}
int main(int argc, const char * argv[]) {
    p22();
    return 0;
}
