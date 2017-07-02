#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include <vector>

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl.H>

#include <GUIFormGenerator.h>
#include <Project.h>

using namespace std;

class GUI : public GUIFormGenerator {

    private:

        Project* project;
        int editInput;

    public:

        GUI();

        void show();

        static void cbQuit(Fl_Widget* btn, void* userdata);

        //wIndex
        static void cbOpen_wI(Fl_Widget* btn, void* userdata);
        static void cbNew_wI(Fl_Widget* btn, void* userdata);

        //wNewProject
        static void cbNew_wNP(Fl_Widget* btn, void* userdata);
        static void cbCancel_wNP(Fl_Widget* btn, void* userdata);

        //wOpenProject
        static void cbOkOpenProject(Fl_Widget* btn, void* userdata);
        static void cbCancelOpenProject(Fl_Widget* btn, void* userdata);

        //wEditProject
        static void cbSaveProject_wEP(Fl_Widget* btn, void* userdata);
        static void cbGenerate_wEP(Fl_Widget* btn, void* userdata);
        static void cbSave_wEP(Fl_Widget* btn, void* userdata);
        static void cbEditTitle_wEP(Fl_Widget* btn, void* userdata);
        static void cbAdd_wEP(Fl_Widget* btn, void* userdata);
        static void cbEdit_wEP(Fl_Widget* btn, void* userdata);
        static void cbRemove_wEP(Fl_Widget* btn, void* userdata);
        static void cbQuit_wEP(Fl_Widget* btn, void* userdata);
        
        //wInputText
        static void cbSave_wIT(Fl_Widget* btn, void* userdata);
        static void cbCancel_wIT(Fl_Widget* btn, void* userdata);

        //wInputSelect
        static void cbSave_wIS(Fl_Widget* btn, void* userdata);
        static void cbCancel_wIS(Fl_Widget* btn, void* userdata);
        static void cbAdd_wIS(Fl_Widget* btn, void* userdata);
        static void cbRemove_wIS(Fl_Widget* btn, void* userdata);

        //wInputRadio
        static void cbSave_wIR(Fl_Widget* btn, void* userdata);
        static void cbCancel_wIR(Fl_Widget* btn, void* userdata);
        static void cbAdd_wIR(Fl_Widget* btn, void* userdata);
        static void cbRemove_wIR(Fl_Widget* btn, void* userdata);
        
};

#endif 