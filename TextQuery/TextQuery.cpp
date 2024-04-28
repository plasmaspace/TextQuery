//
//  TextQuery.cpp
//  TextQuery
//
//  Created by panqj on 3/16/24.
//

#include "TextQuery.hpp"
#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream& infile) : file(new vector<string>){
    string text;
    while(getline(infile,text)){
        file->push_back(text);
        line_no n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word){
            for (int i = 0; i < word.size(); i++) {
                if (ispunct(word[i])) word.erase(i);
            }
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
            }
            auto &lines = qt[word];
            if (!lines) lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string word) {
    shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = qt.find(word);
    if (loc == qt.end()) {
        return QueryResult(word, nodata, file);
    }
    else {
        return QueryResult(word, loc->second, file);
    }
}

ostream& print(ostream& os, const QueryResult& qr) {
    os << qr.word << " occurs " << qr.lines->size() << " tiems" << endl;
    for (auto linNum : *(qr.lines)){
        os << "\tline " << linNum + 1 << ": " << *(qr.file->begin() + linNum) << endl;
    }
    return os;
}
