#include <InputRadio.h>

InputRadio::InputRadio(vector<string> o, string i, string l) : Input(i, l) {

    this->type = "radio";
    this->options = o;
}

string InputRadio::getType() {

    return this->type;
}

vector<string> InputRadio::getOptions() {

    return this->options;
}

string InputRadio::toCSV() {

    string csv;
    csv += this->type + ";" +
           this->id + ";" +
           this->label;

    for(string o : this->options)
        csv += ";" + o;

    csv += "\n";

    return csv;
}

string InputRadio::toBrowser() {

    string info;
    info += "Type: " + this->type + " | " +
            "ID: " + this->id + " | " +
            "Label: " + this->label + " | " +
            "Options: ";
    
    for(string o : this->options)
        info += o + " ~ ";

    info += "\n";

    return info;
}

string InputRadio::toHTML() {

    string info;
    info += "<div class=\"form-group\">\n";
    info += "<label for=\"" + this->id + "\" class=\"col-sm-2 control-label\">" + this->label + "</label>\n";
    info += "<div class=\"col-sm-6\">\n";
    for(string o : this->options) {
        info += "<div class=\"radio\">\n";
        info += "<label>\n";
        info += "<input type=\"radio\" class=\"validate[required]\" name=\"" + this->id + "\" value=\"" + o + "\">\n";
        info += o + "\n";
        info += "</label>\n";
        info += "</div>\n";
    }
    info += "</div>\n</div>\n";

    return info;
}

string InputRadio::toTable() {

    return "{ \"title\": \"" + this->label + "\"}," + '\n';
}