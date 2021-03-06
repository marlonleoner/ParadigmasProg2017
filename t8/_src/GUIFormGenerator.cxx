// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "GUIFormGenerator.h"

Fl_Menu_Item GUIFormGenerator::menu_menu[] = {
 {"Save Project", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"Gerar index.html", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* GUIFormGenerator::menuSave_wEP = GUIFormGenerator::menu_menu + 0;
Fl_Menu_Item* GUIFormGenerator::menuGenerate_wEP = GUIFormGenerator::menu_menu + 1;

GUIFormGenerator::GUIFormGenerator() {
  { wIndex = new Fl_Window(390, 365, "Form Generator");
    wIndex->box(FL_UP_BOX);
    wIndex->color((Fl_Color)55);
    wIndex->user_data((void*)(this));
    wIndex->align(Fl_Align(FL_ALIGN_CENTER));
    { btnNew_wI = new Fl_Button(90, 215, 210, 30, "New Projeto");
      btnNew_wI->box(FL_RFLAT_BOX);
    } // Fl_Button* btnNew_wI
    { btnOpen_wI = new Fl_Button(90, 260, 210, 30, "Open Project");
      btnOpen_wI->box(FL_RFLAT_BOX);
    } // Fl_Button* btnOpen_wI
    { btnQuit_wI = new Fl_Button(315, 325, 65, 30, "Quit");
      btnQuit_wI->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnQuit_wI
    { boxLogo = new Fl_Box(0, 25, 390, 160);
      Fl_PNG_Image* png = new Fl_PNG_Image("img/logo.png");
      boxLogo->image(png);
    } // Fl_Box* boxLogo
    wIndex->end();
  } // Fl_Window* wIndex
  { wNewProject = new Fl_Double_Window(415, 85, "New Project");
    wNewProject->user_data((void*)(this));
    { input_wNP = new Fl_Input(5, 26, 405, 24, "Nome do novo projeto: ");
      input_wNP->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Input* input_wNP
    { btnCancel_wNP = new Fl_Button(340, 55, 70, 25, "Cancel");
    } // Fl_Button* btnCancel_wNP
    { btnNew_wNP = new Fl_Button(255, 55, 80, 25, "New");
    } // Fl_Button* btnNew_wNP
    wNewProject->end();
  } // Fl_Double_Window* wNewProject
  { wOpenProject = new Fl_Double_Window(425, 165, "Open Project");
    wOpenProject->user_data((void*)(this));
    { browserProjects = new Fl_File_Browser(5, 20, 415, 110, "Your Projects");
      browserProjects->type(2);
      browserProjects->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      browserProjects->window()->hotspot(browserProjects);
      browserProjects->filter("*.csv");
      browserProjects->load("project");
    } // Fl_File_Browser* browserProjects
    { btnCancel_wOP = new Fl_Button(350, 135, 70, 25, "Cancel");
    } // Fl_Button* btnCancel_wOP
    { btnOpen_wOP = new Fl_Button(275, 135, 70, 25, "Open");
    } // Fl_Button* btnOpen_wOP
    wOpenProject->end();
  } // Fl_Double_Window* wOpenProject
  { wEditProject = new Fl_Window(410, 380);
    wEditProject->color((Fl_Color)55);
    wEditProject->user_data((void*)(this));
    wEditProject->align(Fl_Align(FL_ALIGN_CENTER));
    { menu = new Fl_Menu_Bar(0, 0, 410, 25);
      menu->menu(menu_menu);
    } // Fl_Menu_Bar* menu
    { inputTitle = new Fl_Input(50, 41, 235, 26, "Title: ");
      inputTitle->deactivate();
    } // Fl_Input* inputTitle
    { browserInputs = new Fl_Browser(5, 95, 400, 245, "Inputs: ");
      browserInputs->type(2);
      browserInputs->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Browser* browserInputs
    { btnEditTitle_wEP = new Fl_Button(350, 40, 55, 30, "Edit");
      btnEditTitle_wEP->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnEditTitle_wEP
    { btnSave_wEP = new Fl_Button(290, 40, 55, 30, "Save");
      btnSave_wEP->box(FL_ENGRAVED_BOX);
      btnSave_wEP->deactivate();
    } // Fl_Button* btnSave_wEP
    { btnAdd_wEP = new Fl_Button(5, 345, 65, 30, "Add");
      btnAdd_wEP->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnAdd_wEP
    { btnEdit_wEP = new Fl_Button(75, 345, 65, 30, "Edit");
      btnEdit_wEP->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnEdit_wEP
    { btnQuit_wEP = new Fl_Button(340, 345, 65, 30, "Quit");
      btnQuit_wEP->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnQuit_wEP
    { btnRemove_wEP = new Fl_Button(145, 345, 65, 30, "Remove");
      btnRemove_wEP->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnRemove_wEP
    wEditProject->end();
  } // Fl_Window* wEditProject
  { wInputText = new Fl_Double_Window(325, 135, "Add Input - <text>");
    wInputText->color((Fl_Color)55);
    wInputText->user_data((void*)(this));
    { inputLabel_wIT = new Fl_Input(55, 21, 265, 28, "Label: ");
      inputLabel_wIT->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputLabel_wIT
    { inputID_wIT = new Fl_Input(55, 57, 265, 28, "ID: ");
      inputID_wIT->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputID_wIT
    { btnSave_wIT = new Fl_Button(55, 100, 200, 30, "Save Input");
      btnSave_wIT->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnSave_wIT
    { btnCancel_wIT = new Fl_Button(260, 100, 60, 30, "Cancel");
      btnCancel_wIT->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnCancel_wIT
    wInputText->end();
  } // Fl_Double_Window* wInputText
  { wInputSelect = new Fl_Double_Window(335, 320, "Add Input - <select>");
    wInputSelect->color((Fl_Color)55);
    wInputSelect->user_data((void*)(this));
    { inputLabel_wIS = new Fl_Input(65, 22, 265, 28, "Label: ");
      inputLabel_wIS->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputLabel_wIS
    { inputID_wIS = new Fl_Input(65, 57, 265, 28, "ID: ");
      inputID_wIS->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputID_wIS
    { btnSave_wIS = new Fl_Button(65, 285, 200, 30, "Save Input");
      btnSave_wIS->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnSave_wIS
    { btnCancel_wIS = new Fl_Button(270, 285, 60, 30, "Cancel");
      btnCancel_wIS->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnCancel_wIS
    { browserOp_wIS = new Fl_Browser(65, 90, 265, 145, "Options");
      browserOp_wIS->type(2);
      browserOp_wIS->align(Fl_Align(FL_ALIGN_LEFT_TOP));
    } // Fl_Browser* browserOp_wIS
    { btnAddOp_wIS = new Fl_Button(65, 240, 130, 30, "Add Op");
    } // Fl_Button* btnAddOp_wIS
    { btnRemoveOp_wIS = new Fl_Button(200, 240, 130, 30, "Remove Op");
    } // Fl_Button* btnRemoveOp_wIS
    wInputSelect->end();
  } // Fl_Double_Window* wInputSelect
  { wInputRadio = new Fl_Double_Window(335, 320, "Add Input - <radio>");
    wInputRadio->color((Fl_Color)55);
    wInputRadio->user_data((void*)(this));
    { inputLabel_wIR = new Fl_Input(65, 22, 265, 28, "Label: ");
      inputLabel_wIR->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputLabel_wIR
    { inputID_wIR = new Fl_Input(65, 57, 265, 28, "ID: ");
      inputID_wIR->box(FL_THIN_UP_BOX);
    } // Fl_Input* inputID_wIR
    { btnSave_wIR = new Fl_Button(65, 285, 200, 30, "Save Input");
      btnSave_wIR->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnSave_wIR
    { btnCancel_wIR = new Fl_Button(270, 285, 60, 30, "Cancel");
      btnCancel_wIR->box(FL_ENGRAVED_BOX);
    } // Fl_Button* btnCancel_wIR
    { browserOp_wIR = new Fl_Browser(65, 90, 265, 145, "Options");
      browserOp_wIR->align(Fl_Align(FL_ALIGN_LEFT_TOP));
    } // Fl_Browser* browserOp_wIR
    { btnAddOp_wIR = new Fl_Button(65, 240, 125, 30, "Add Op");
    } // Fl_Button* btnAddOp_wIR
    { btnRemoveOp_wIR = new Fl_Button(205, 240, 125, 30, "Remove Op");
    } // Fl_Button* btnRemoveOp_wIR
    wInputRadio->end();
  } // Fl_Double_Window* wInputRadio
}
