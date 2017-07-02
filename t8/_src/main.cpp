#include <GUI.h>

#include <Project.h>

int main(int argc, char const *argv[]) {
    
    GUI gui;
    gui.show();

    return Fl::run();
}