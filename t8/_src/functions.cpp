#include <functions.h>

vector< string > split(const string& str, char delim) {

    stringstream ss(str);
    string tok;
    vector<string> vec;
    
    while (getline(ss, tok, delim)) {
    
        if (!tok.empty())
            vec.push_back(tok);
    }
    
    return vec;
}