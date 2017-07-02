#include <GUI.h>

GUI::GUI() {

    editInput = 0;

    //wIndex - wI
    btnNew_wI->callback((Fl_Callback*) cbNew_wI, (void*)(this));
    btnOpen_wI->callback((Fl_Callback*) cbOpen_wI, (void*)(this));
    btnQuit_wI->callback((Fl_Callback*) cbQuit, (void*)(this));    

    //wNewProject - wNP
    btnNew_wNP->callback((Fl_Callback*) cbNew_wNP, (void*)(this));
    btnCancel_wNP->callback((Fl_Callback*) cbCancel_wNP, (void*)(this));

    //wOpenProject - wOP
    btnOpen_wOP->callback((Fl_Callback*) cbOkOpenProject, (void*)(this));
    btnCancel_wOP->callback((Fl_Callback*) cbCancelOpenProject, (void*)(this));

    //wEditProject - wEP
    menuSave_wEP->callback((Fl_Callback*) cbSaveProject_wEP, (void*)(this));
    menuGenerate_wEP->callback((Fl_Callback*) cbGenerate_wEP, (void*)(this));
    btnSave_wEP->callback((Fl_Callback*) cbSave_wEP, (void*)(this));
    btnEditTitle_wEP->callback((Fl_Callback*) cbEditTitle_wEP, (void*)(this));
    btnAdd_wEP->callback((Fl_Callback*) cbAdd_wEP, (void*)(this));
    btnEdit_wEP->callback((Fl_Callback*) cbEdit_wEP, (void*)(this));
    btnRemove_wEP->callback((Fl_Callback*) cbRemove_wEP, (void*)(this));
    btnQuit_wEP->callback((Fl_Callback*) cbQuit_wEP, (void*)(this));

    //wInputText - wIT
    btnSave_wIT->callback((Fl_Callback*) cbSave_wIT, (void*)(this));
    btnCancel_wIT->callback((Fl_Callback*) cbCancel_wIT, (void*)(this));

    //wInputSelect - wIS
    btnSave_wIS->callback((Fl_Callback*) cbSave_wIS, (void*)(this));
    btnCancel_wIS->callback((Fl_Callback*) cbCancel_wIS, (void*)(this));
    btnAddOp_wIS->callback((Fl_Callback*) cbAdd_wIS, (void*)(this));
    btnRemoveOp_wIS->callback((Fl_Callback*) cbRemove_wIS, (void*)(this));

    //wInputRadio - wIR
    btnSave_wIR->callback((Fl_Callback*) cbSave_wIR, (void*)(this));
    btnCancel_wIR->callback((Fl_Callback*) cbCancel_wIR, (void*)(this));
    btnAddOp_wIR->callback((Fl_Callback*) cbAdd_wIR, (void*)(this));
    btnRemoveOp_wIR->callback((Fl_Callback*) cbRemove_wIR, (void*)(this));
}

void GUI::show() {

    this->wIndex->show();
}

void GUI::cbQuit(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wIndex->hide();

    exit(0);
}

//wIndex
void GUI::cbOpen_wI(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wOpenProject->set_modal();
    gui->wOpenProject->show();
}

void GUI::cbNew_wI(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wNewProject->set_modal();
    gui->wNewProject->show();
}

//wNewProject
void GUI::cbNew_wNP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string newProject = gui->input_wNP->value();
    newProject += ".csv";

    for(int i = 1 ; i <= gui->browserProjects->size() ; i++) {

        if(newProject == gui->browserProjects->text(i)) {
            fl_alert("Já existe projeto com este nome.\nSelecione outro nome!");
            return;
        }
    }

    gui->project = new Project("project/" + newProject);

    gui->wNewProject->hide();
    gui->wIndex->hide();

    gui->inputTitle->value(gui->project->getTitle().c_str());
    gui->wEditProject->copy_label((gui->project->getNameProject() + 
                                   " - " +
                                   gui->project->getTitle()).c_str());

    for(Input* i : gui->project->getInputs())
        gui->browserInputs->add(i->toBrowser().c_str());
    
    gui->wEditProject->show();
}

void GUI::cbCancel_wNP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wNewProject->hide();
    gui->wIndex->set_modal();
}

//wOpenProject
void GUI::cbOkOpenProject(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    int value = gui->browserProjects->value();
    if(value == 0) {
        fl_alert("Selecione um projeto!");
        return;
    }

    string csvProject = gui->browserProjects->text(value);
    if(!fl_filename_match(csvProject.c_str(), "*.csv")) {
        fl_alert("Selecione um arquivo válido (<name>.csv).");
        return;
    }

    gui->project = new Project("project/" + csvProject);
    gui->project->openProject();

    gui->wOpenProject->hide();
    gui->wIndex->hide();

    gui->inputTitle->value(gui->project->getTitle().c_str());
    gui->wEditProject->copy_label((gui->project->getNameProject() + 
                                   " - " +
                                   gui->project->getTitle()).c_str());

    for(Input* i : gui->project->getInputs())
        gui->browserInputs->add(i->toBrowser().c_str());
    
    gui->wEditProject->show();
}

void GUI::cbCancelOpenProject(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wOpenProject->hide();
    gui->wIndex->set_modal();
}

//wEditProject

void GUI::cbSaveProject_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    if(gui->project->getTitle() == "") {
        fl_alert("Title Vazio!");
        return;
    }

    gui->project->saveProject();

    fl_alert("Projeto Salvo!");
}

void GUI::cbGenerate_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    if(gui->project->getTitle() == "") {
        fl_alert("Title Vazio!");
        return;
    }

    gui->project->generator();

    fl_alert("index.html gerado com sucesso!");
}

void GUI::cbSave_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->project->setTitle(gui->inputTitle->value());
    gui->wEditProject->copy_label((gui->project->getNameProject() + 
                                   " - " +
                                   gui->project->getTitle()).c_str());
    gui->inputTitle->deactivate();
    gui->btnSave_wEP->deactivate();
    gui->btnEdit_wEP->activate();
}

void GUI::cbEditTitle_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->inputTitle->activate();
    gui->btnSave_wEP->activate();
    gui->btnEdit_wEP->deactivate();
}

void GUI::cbAdd_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    switch ( fl_choice("Qual Input deseja adicionar ?", "Select", "Text", "Radio") ) {
        case 0:

            gui->wInputSelect->set_modal();
            gui->wInputSelect->show();

            break;

        case 1:

            gui->wInputText->set_modal();
            gui->wInputText->show();

            break;
        
        case 2:

            gui->wInputRadio->set_modal();
            gui->wInputRadio->show();

            break;
    }
}

void GUI::cbEdit_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    int value = gui->browserInputs->value();
    if(value == 0) {
        fl_alert("Selecione o INPUT a ser editado!");
        return;
    }

    gui->editInput = value;

    Input* i = gui->project->getInput(value - 1);
    if(i->getType() == "text") {

        gui->inputID_wIT->value(i->getID().c_str());
        gui->inputLabel_wIT->value(i->getLabel().c_str());

        gui->inputID_wIT->deactivate();
        gui->wInputText->set_modal();
        gui->wInputText->show();
    }else if(i->getType() == "select") {

        gui->inputID_wIS->value(i->getID().c_str());
        gui->inputLabel_wIS->value(i->getLabel().c_str());
        gui->browserOp_wIS->clear();
        for(string s : i->getOptions())
            gui->browserOp_wIS->add(s.c_str());

        gui->inputID_wIS->deactivate();
        gui->wInputSelect->set_modal();
        gui->wInputSelect->show();
    }else if(i->getType() == "radio") {

        gui->inputID_wIR->value(i->getID().c_str());
        gui->inputLabel_wIR->value(i->getLabel().c_str());
        gui->browserOp_wIR->clear();
        for(string s : i->getOptions())
            gui->browserOp_wIR->add(s.c_str());

        gui->inputID_wIR->deactivate();
        gui->wInputRadio->set_modal();
        gui->wInputRadio->show();        
    }
}

void GUI::cbRemove_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    int value = gui->browserInputs->value();
    if(value == 0) {
        fl_alert("Selecione o INPUT a ser removido!");
        return;
    }

    gui->browserInputs->remove(value);
    gui->project->removeInput(value - 1);
}

void GUI::cbQuit_wEP(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wEditProject->hide();
    exit(0);
}

//wInputText

void GUI::cbSave_wIT(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string id = gui->inputID_wIT->value();
    string label = gui->inputLabel_wIT->value();

    if(label == "\0" || id == "\0") {
        fl_alert("ID ou Label vazio!");
        return;
    }

    for(Input* i : gui->project->getInputs()) {
        if(i->getID() == id && gui->editInput == 0) {
            fl_alert("Já existe INPUT com este nome!");
            return;
        }
    }

    InputText* i = new InputText(id, label);
    if(gui->editInput > 0) {
        
        gui->project->editInput(i, gui->editInput - 1);
        gui->browserInputs->text(gui->editInput, gui->project->getInput(gui->editInput - 1)->toBrowser().c_str());
    }else {

        gui->project->addInput(i);
        gui->browserInputs->add(i->toBrowser().c_str());
    }

    fl_alert("InputText adicionado com sucesso!");

    gui->wInputText->hide();
    gui->inputLabel_wIT->value('\0');
    gui->inputID_wIT->value('\0');
    gui->editInput = 0;
}

void GUI::cbCancel_wIT(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wInputText->hide();
    gui->inputLabel_wIT->value("\0");
    gui->inputID_wIT->value("\0");
}


//wInputSelect

void GUI::cbSave_wIS(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string id = gui->inputID_wIS->value();
    string label = gui->inputLabel_wIS->value();

    if(label == "\0" || id == "\0") {
        fl_alert("ID ou Label vazio!");
        return;
    }

    for(Input* i : gui->project->getInputs()) {
        if(i->getID() == id && gui->editInput == 0) {
            fl_alert("Já existe INPUT com este nome!");
            return;
        }
    }

    vector<string> o;
    for(int i = 1 ; i <= gui->browserOp_wIS->size() ; i++) {

        o.push_back(gui->browserOp_wIS->text(i));
    }

    InputSelect* i = new InputSelect(o, id, label);
    if(gui->editInput > 0) {
        
        gui->project->editInput(i, gui->editInput - 1);
        gui->browserInputs->text(gui->editInput, gui->project->getInput(gui->editInput - 1)->toBrowser().c_str());
    }else {

        gui->project->addInput(i);
        gui->browserInputs->add(i->toBrowser().c_str());
    }

    fl_alert("InputSelect adicionado com sucesso!");

    gui->wInputSelect->hide();
    gui->inputLabel_wIS->value("\0");
    gui->inputID_wIS->value("\0");
    gui->editInput = 0;
}

void GUI::cbCancel_wIS(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wInputSelect->hide();
    gui->inputID_wIT->value("\0");
    gui->inputLabel_wIT->value("\0");
}

void GUI::cbAdd_wIS(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string op = fl_input("Nome da opção: ");
    if(op == "\0") {
        fl_alert("Nome Vazio!");
        return;
    }

    gui->browserOp_wIS->add(op.c_str());
}

void GUI::cbRemove_wIS(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    int value = gui->browserOp_wIS->value();
    if(value == 0) {
        fl_alert("Selecione o OPTION a ser removido!");
        return;
    }

    gui->browserOp_wIS->remove(value);
}

//wInputRadio

void GUI::cbSave_wIR(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string id = gui->inputID_wIR->value();
    string label = gui->inputLabel_wIR->value();

    if(label == "\0" || id == "\0") {
        fl_alert("ID ou Label vazio!");
        return;
    }

    for(Input* i : gui->project->getInputs()) {
        if(i->getID() == id && gui->editInput == 0) {
            fl_alert("Já existe INPUT com este nome!");
            return;
        }
    }

    vector<string> o;
    for(int i = 1 ; i <= gui->browserOp_wIR->size() ; i++) {

        o.push_back(gui->browserOp_wIR->text(i));
    }

    InputRadio* i = new InputRadio(o, id, label);
    if(gui->editInput > 0) {
        
        gui->project->editInput(i, gui->editInput - 1);
        gui->browserInputs->text(gui->editInput, gui->project->getInput(gui->editInput - 1)->toBrowser().c_str());
    }else {

        gui->project->addInput(i);
        gui->browserInputs->add(i->toBrowser().c_str());
    }

    fl_alert("InputRadio adicionado com sucesso!");

    gui->wInputRadio->hide();
    gui->inputLabel_wIR->value("\0");
    gui->inputID_wIR->value("\0");
    gui->editInput = 0;
}

void GUI::cbCancel_wIR(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    gui->wInputRadio->hide();
    gui->inputID_wIR->value("\0");
    gui->inputLabel_wIR->value("\0");
}

void GUI::cbAdd_wIR(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    string op = fl_input("Nome da opção: ");
    if(op == "\0") {
        fl_alert("Nome Vazio!");
        return;
    }

    gui->browserOp_wIR->add(op.c_str());
}

void GUI::cbRemove_wIR(Fl_Widget* btn, void* userdata) {
    GUI* gui = static_cast<GUI*>(userdata);

    int value = gui->browserOp_wIR->value();
    if(value == 0) {
        fl_alert("Selecione o OPTION a ser removido!");
        return;
    }

    gui->browserOp_wIR->remove(value);
}
