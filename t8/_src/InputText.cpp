#include <InputText.h>

InputText::InputText(string i, string l) : Input(i, l) {

    this->type = "text";
}

string InputText::getType() {

    return this->type;
}

vector<string> InputText::getOptions() {

    vector<string> o;

    return o;
}

string InputText::toCSV() {

    return this->type + ";" +
           this->id + ";" +
           this->label + "\n";
}

string InputText::toBrowser() {

    return "Type: " + this->type + " | " +
           "ID: " + this->id + " | " +
           "Label: " + this->label + "\n";
}

string InputText::toHTML() {

    string info;
    info += "<div class=\"form-group\">\n";
    info += "<label for=\"" + this->id + "\" class=\"col-sm-2 control-label\">" + this->label + "</label>\n";
    info += "<div class=\"col-sm-6\">\n";
    info += "<input type=\"" + this->type + "\" class=\"form-control validate[required]\" id=\"" + this->id + "\" placeholder=\"" + this->label + "\">\n";
    info += "</div>\n</div>\n";

    return info;
}

string InputText::toTable() {

    return "{ \"title\": \"" + this->label + "\"}," + '\n';
}