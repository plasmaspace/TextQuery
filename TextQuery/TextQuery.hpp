//
//  TextQuery.hpp
//  TextQuery
//
//  Created by panqj on 3/16/24.
//

#ifndef TextQuery_hpp
#define TextQuery_hpp

#include "TextQueryResult.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <map>

using std::ifstream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::map;

class TextQuery{
public:
    typedef vector<string>::size_type line_no;
    TextQuery(ifstream&);
    QueryResult query(const string);
private:
    map<string,shared_ptr<set<line_no>>> qt;
    shared_ptr<vector<string>> file;
};

#endif /* TextQuery_hpp */
