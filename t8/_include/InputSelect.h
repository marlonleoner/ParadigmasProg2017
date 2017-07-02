#ifndef InputSelect_H
#define InputSelect_H

#include <string>
#include <vector>

#include <Input.h>

using namespace std;

class InputSelect : public Input {
    
    private:
        
        vector<string> options;

    public:

        InputSelect(vector<string> o, string i, string l);

        string getType();

        vector<string> getOptions();

        string toCSV();

        string toBrowser();

        string toHTML();

        string toTable();

};

#endif 