#ifndef Project_H
#define Project_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <InputText.h>
#include <InputSelect.h>
#include <InputRadio.h> 
#include <functions.h>

using namespace std;

class Project {
    
    private:

        string nameProject;

        string title;

        vector<Input*> inputs;

        string titleHTML();

        string h1HTML();

        string inputsHTML();

        string inputsDataSet();

        string inputsTable();

        string inputsTable2();

        string inputsSave();

    public:

        Project(string nameProject);

        Project(string nameProject, string title, vector<Input*> inputs);

        string getNameProject();

        string getTitle();

        Input* getInput(int v);

        vector<Input*> getInputs();

        void setTitle(string title);

        void addInput(Input* i);

        void editInput(Input* i, int v);

        void removeInput(int p);

        void saveProject();

        void openProject();

        void generator();

};

#endif 