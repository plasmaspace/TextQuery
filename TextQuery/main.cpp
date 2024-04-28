//
//  main.cpp
//  TextQuery
//
//  Created by panqj on 3/16/24.
//

#include <iostream>
#include "TextQuery.hpp"

using namespace std;

void runQuery(ifstream& infile){
    TextQuery qt(infile);
    cout << "enter a word to search, or q to quit: " << endl;
    string word;
    while(cin >> word){
        if (word.empty() || word == "q") break;
        print(cout, qt.query(word));
    }
}

int main() {
    ifstream infile("./storyDataFile");
    runQuery(infile);
    return 0;
}
