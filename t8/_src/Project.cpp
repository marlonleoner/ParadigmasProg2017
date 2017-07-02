#include <Project.h>

Project::Project(string nameProject) {

    this->nameProject = nameProject;
}

Project::Project(string nameProject, string title, vector<Input*> inputs) {

    this->nameProject = nameProject;
    this->title = title;
    this->inputs = inputs;
}

string Project::getNameProject() {

    return this->nameProject;
}

string Project::getTitle() {

    return this->title;
}

Input* Project::getInput(int v) {


    return this->inputs[v];
}

vector<Input*> Project::getInputs() {

    return this->inputs;
}

void Project::setTitle(string title) {

    this->title = title;
}

void Project::addInput(Input* i) {

    this->inputs.push_back(i);
}

void Project::editInput(Input* i, int v) {

    this->inputs.erase(this->inputs.begin() + v);
    this->inputs.insert(this->inputs.begin() + v, i);
}

void Project::removeInput(int p) {

    this->inputs.erase(this->inputs.begin() + p);
}

void Project::saveProject(){

    fstream file(this->nameProject.c_str(), fstream::out);
    
    file << this->title + '\n';

    for(Input* i : this->inputs) {
        file << (i->toCSV()).c_str();
    }

    file.close();
}

void Project::openProject() {

    ifstream file(this->nameProject.c_str());
    
    string line;

    getline(file, this->title);

    while(getline(file, line)) {

        int idExiste = 0;

        vector<string> aux = split(line, ';');

        for(Input* i : this->inputs) {
            if(i->getID() == aux[1])
                idExiste = 1;
        }

        if(idExiste > 0) {
            continue;
        }

        if(aux[0] == "text")
            this->inputs.push_back(new InputText(aux[1], aux[2]));
        else if(aux[0] == "select") {

            vector<string> o;

            for(unsigned int i = 3 ; i < aux.size() ; i++)
                o.push_back(aux[i]);

            this->inputs.push_back(new InputSelect(o, aux[1], aux[2]));
        }else if(aux[0] == "radio") {

            vector<string> o;

            for(unsigned int i = 3 ; i < aux.size() ; i++)
                o.push_back(aux[i]);

            this->inputs.push_back(new InputRadio(o, aux[1], aux[2]));
        }
    }

    file.close();
}

void Project::generator() {

    ifstream templateFile("HTML/template.html");
    fstream indexFile("HTML/index.html", fstream::out);

    string line;

    while(getline(templateFile, line)) {

        if(line == ">>>1<<<") {

            indexFile << this->titleHTML();
        }else if(line == ">>>2<<<") {

            indexFile << this->h1HTML();
        }else if(line == ">>>3<<<") {

            indexFile << this->inputsHTML();
        }else if(line == ">>>4<<<") {
            
            indexFile << this->inputsDataSet();
        }else if(line == ">>>5<<<") {
            
            indexFile << this->inputsTable();
        }else if(line == ">>>6<<<") {
            
            indexFile << this->inputsTable2();
        }else if(line == ">>>7<<<") {
            
            indexFile << this->inputsSave();
        }else {

            indexFile << line + '\n';
        }

    }
}

string Project::titleHTML() {

    return "<title>" + this->title + "</title>" + '\n';
}

string Project::h1HTML() {

    return "<h1>" + this->title + "</h1>" + '\n';
}

string Project::inputsHTML() {

    string input;

    for(Input* i : this->inputs)
        input += i->toHTML();

    return input;
}

string Project::inputsDataSet() {

    string info;
    info += "dataSet[seq]=[index, icons";
    for(Input* i : this->inputs)
        info += ", object." + i->getID();
    info += "];\n";

    return info;
}

string Project::inputsTable() {

    string info;
    info += "oTable=$('#table').dataTable({\n";
    info += "\"data\": dataSet,\n";
    info += "\"columns\": [\n";
    info += "{ \"title\": \"Seq\", \"class\": \"center\" },\n";
    info += "{ \"title\": \"\", \"class\": \"center\" },\n";
    for(Input* i : this->inputs)
        info += i->toTable();
    info += "]\n});\n";

    return info;
}

string Project::inputsTable2() {

    int cont = 2;
    string info;
    info += "$('#table tbody').on( 'click', '.glyphicon-edit', function () {\n";
    info += "$('#list').hide();\n";
    info += "var rows = $(this).parents('tr').children();\n";
    info += "$('#seq').text(rows[0].innerHTML);\n";
    for(Input* i : this->inputs) {
        if(i->getType() == "radio")
            info += "$('input[name=\"" + i->getID() + "\"]').val([rows[" + to_string(cont) + "].innerHTML]);\n";
        else
            info += "$('#" + i->getID() + "').val(rows[" + to_string(cont) + "].innerHTML);\n";

        cont++;
    }
    info += "$('#formID').show();\n} );\n";

    return info;
}

string Project::inputsSave() {

    string info;
    info += "function save() {\n";
    info += "  var seq=$('#seq').text();\n";
    info += "  if ( isNaN(seq) ) { seq=0; }\n";
    info += "  var key=formId+\"_\"+seq;\n";
    info += "  var object={\n";
    for(Input* i : this->inputs) {
        if(i->getType() == "radio")
            info += "\"" + i->getID() + "\":$('input[name=\"" + i->getID() + "\"]:checked').val(),";
        else
            info += "\"" + i->getID() + "\":$(\"#" + i->getID() + "\").val(),\n";
    }
    info += "}\nlocalStorage.setItem(key, JSON.stringify(object));\n}\n";

    return info;
}