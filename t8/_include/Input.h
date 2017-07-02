#ifndef Input_H
#define Input_H

#include <string>
#include <vector>

using namespace std;

class Input {
    
    protected:
        
        string type,
               id,
               label;

    public:

        Input(string i, string l);

        string getID();

        string getLabel();

        virtual string getType() = 0;

        virtual vector<string> getOptions() = 0;

        virtual string toCSV() = 0;

        virtual string toBrowser() = 0;

        virtual string toHTML() = 0;

        virtual string toTable() = 0;

};

#endif 