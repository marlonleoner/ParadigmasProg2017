#include <InputSelect.h>

InputSelect::InputSelect(vector<string> o, string i, string l) : Input(i, l) {

    this->type = "select";
    this->options = o;
}

string InputSelect::getType() {

    return this->type;
}

vector<string> InputSelect::getOptions() {

    return this->options;
}

string InputSelect::toCSV() {

    string csv;
    csv += this->type + ";" +
           this->id + ";" +
           this->label;

    for(string o : this->options)
        csv += ";" + o;

    csv += "\n";

    return csv;
}

string InputSelect::toBrowser() {

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

string InputSelect::toHTML() {

    string info;
    info += "<div class=\"form-group\">\n";
    info += "   <label for=\"" + this->id + "\" class=\"col-sm-2 control-label\">" + this->label + "</label>\n";
    info += "    <div class=\"col-sm-6\">\n";
    info += "        <select id=\"" + this->id + "\" class=\"form-control\">\n";
    for(string o : this->options)
        info += "            <option value=\"" + o + "\">" + o + "</option>\n";
    info += "        </select>\n";
    info += "    </div>\n</div>\n";

    return info;
}

string InputSelect::toTable() {

    return "{ \"title\": \"" + this->label + "\"}," + '\n';
}