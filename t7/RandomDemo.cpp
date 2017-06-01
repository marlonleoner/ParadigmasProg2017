#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <FL/fl_ask.H>

#include <RandomDemo.h>

using namespace std;

class RandomSorteio : public RandomDemo {

    private:

        int nrParticipantes;
        vector<int> nrSorteados;
        int nrGanhador;

    public:

        RandomSorteio() {
            btnReset->callback((Fl_Callback*) cbReset, (void*)(this));
            btnSortear->callback((Fl_Callback*) cbSortear, (void*)(this));
            btnCloseError->callback((Fl_Callback*) cbClose, (void*)(this));

            this->nrGanhador = 1;
        }

        void showError(const char* error) {
            this->wError->show();
            this->boxError->copy_label(error);
        }

        void show() {
            this->w->show();
        }

        void limiteSorteio() {
            if(this->nrSorteados.size() >= this->nrParticipantes) {
                throw exception();
            }
        }

        static void cbClose(Fl_Widget* btn, void* userdata) {
            RandomSorteio* gui = static_cast<RandomSorteio*>(userdata);

            gui->wError->hide();
        }

        static void cbReset(Fl_Widget* btn, void* userdata) {
            RandomSorteio* gui = static_cast<RandomSorteio*>(userdata);

            gui->nrGanhador = 1;

            gui->nrSorteados.clear();

            gui->inputParticipantes->activate();

            gui->inputParticipantes->value('\0');
            gui->boxNrGanhador->copy_label('\0');
            gui->boxNrSorteado->copy_label('\0');
        }

        static void cbSortear(Fl_Widget* btn, void* userdata) {

            try {
                RandomSorteio* gui = static_cast<RandomSorteio*>(userdata);

                bool sorteandoNr;

                int nrRamdom;

                gui->nrParticipantes = stoi(gui->inputParticipantes->value());

                gui->limiteSorteio();

                do {
                    nrRamdom = rand()%gui->nrParticipantes + 1;

                    sorteandoNr = find(gui->nrSorteados.begin(), gui->nrSorteados.end(), nrRamdom) != gui->nrSorteados.end() ? true : false;
                }while(sorteandoNr);

                gui->boxNrGanhador->copy_label((to_string(gui->nrGanhador) + "º Ganhador").c_str());

                gui->boxNrSorteado->copy_label((to_string(nrRamdom)).c_str());

                gui->inputParticipantes->deactivate();

                gui->nrGanhador++;
                gui->nrSorteados.push_back(nrRamdom);
            }catch(invalid_argument&) {
                fl_alert("Entrada Inválida!");
            }catch(exception&) {
                fl_alert("Todos os números foram sortados.\nReinicie o sorteio!");
            }
        }
};

int main() {
    RandomSorteio gui;
    gui.show();

    return Fl::run();
}
