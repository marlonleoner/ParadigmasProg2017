#ifndef InputRadio_H
#define InputRadio_H

#include <string>
#include <vector>

#include <Input.h>

using namespace std;

class InputRadio : public Input {
    
    private:
        
        vector<string> options;

    public:

        InputRadio(vector<string> o, string i, string l);

        string getType();

        vector<string> getOptions();

        string toCSV();

        string toBrowser();

        string toHTML();

        string toTable();

};

#endif 