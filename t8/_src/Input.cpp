#include <Input.h>

Input::Input(string i, string l) {
    
    this->id = i;
    this->label = l;
}

string Input::getID() {

    return this->id;
}

string Input::getLabel() {

    return this->label;
}