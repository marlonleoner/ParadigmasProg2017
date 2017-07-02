#ifndef InputText_H
#define InputText_H

#include <string>
#include <vector>

#include <Input.h>

using namespace std;

class InputText : public Input {
    
    public:

        InputText(string i, string l);

        string getType();
        
        vector<string> getOptions();

        string toCSV();

        string toBrowser();

        string toHTML();

        string toTable();

};

#endif 