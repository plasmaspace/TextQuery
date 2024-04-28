//
//  TextQueryResult.h
//  TextQuery
//
//  Created by panqj on 3/17/24.
//

#ifndef TextQueryResult_h
#define TextQueryResult_h
#include <string>
#include <set>
#include <memory>
#include <vector>
#include <iostream>

using std::vector;
using std::set;
using std::shared_ptr;
using std::string;
using std::ostream;

class QueryResult {
    friend ostream& print(ostream&,const QueryResult&);
public:
    typedef vector<string>::size_type line_no;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : word(s),lines(p),file(f){}
private:
    string word;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

#endif /* TextQueryResult_h */
