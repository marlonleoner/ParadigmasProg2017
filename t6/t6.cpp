#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h> //rand && atoi

#include <algorithm> //Sort

using namespace std;

#define PI 3.14159265359

class Forma {

    public:

        virtual double getArea() {

        }
};

class Circulo : public Forma {

    private:

        double raio;

    public:

        Circulo(double r) {
            this->raio = r;
        }

        double getArea() {
            return PI * (this->raio * this->raio);
        }

};

class Retangulo : public Forma {

    private:

        double base,
               altura;

    public:

        Retangulo(double b, double a) {
            this->base = b;
            this->altura = a;
        }

        double getArea() {
            return this->base * this->altura;
        }

};

class Triangulo : public Forma{

    private:

        double base,
               altura;

    public:

        Triangulo(double b, double a) {
            this->base = b;
            this->altura = a;
        }

        double getArea() {
            return (this->base * this->altura) / 3.0;
        }
};

class Biscoito {

    private:

        Forma* forma;
        double area;

    public:

        Biscoito(Forma* f) {
            this->forma = f;
            this-> area = this->forma->getArea();
        }

        double getArea() {
            return this->area;
        }

        bool operator<(Biscoito& b) {
            return b.area < this->area;
        }

        string toString() {
            return "Área: " + to_string(this->area) + "\n";
        }
};

class loteBiscoitos {

    private:

        vector<Biscoito> lote;
        
    public:

        loteBiscoitos() {  }

        void addBiscoito(Biscoito b) {
            this->lote.push_back(b);
        }

        void sortB() {
            sort(lote.begin(), lote.end());
        }

        string toString() {
            string infos = "";

            for(Biscoito b : lote) {
                infos += b.toString();
            }

            return infos;
        }

        int qtdPequenos() {
            int qtd = 0;

            for(Biscoito b : lote) {
                if(b.getArea() > 0 && b.getArea() <= 5)
                    qtd++;
            }

            return qtd;
        }

        int qtdMedios() {
            int qtd = 0;

            for(Biscoito b : lote) {
                if(b.getArea() > 5 && b.getArea() <= 10)
                    qtd++;
            }

            return qtd;
        }

        int qtdGrandes() {
            int qtd = 0;

            for(Biscoito b : lote) {
                if(b.getArea() > 10 && b.getArea() <= 16)
                    qtd++;
            }

            return qtd;
        }

};

double randD(int h) {

    double r = rand();
    return (r / (((double) RAND_MAX + 1.0) / (double) h));
}

//10 ~ 16 = 0.60
//5 ~ 9 = 0.40
//0 ~ 4 = 0.20

int main(int args, char** argv) {

    int nrBiscoitos;

    loteBiscoitos l;
	
    srand((unsigned) time(NULL));

    if(args < 2) {
        cout << "Quantidade de Biscoito: ";
        cin >> nrBiscoitos;
    }else {
        nrBiscoitos = atoi(argv[1]);
    }

    for(int i = 0 ; i < nrBiscoitos ; i++) {
        switch(rand()%3) {
            //Circulo
            case 0: {

                Circulo c(randD(1) + 1);
                l.addBiscoito(Biscoito(&c));

                break;
            }

            //Retangulo
            case 1: {

                Retangulo r(randD(3) + 1, randD(3) + 1);
                l.addBiscoito(Biscoito(&r));

                break;
            }

            //Triangulo
            case 2: {

                Triangulo t(randD(3) + 2, randD(3) + 2);
                l.addBiscoito(Biscoito(&t));

                break;
            }
        }
    }

    l.sortB();
	
    cout << l.toString() << endl;

    cout << "Pequenos: " << l.qtdPequenos() << endl;
    cout << "Médios: " << l.qtdMedios() << endl;
    cout << "Grandes: " << l.qtdGrandes() << endl;

    cout << "\nGanhos Previstos: R$ " << l.qtdPequenos() * 0.20 + l.qtdMedios() * 0.40 + l.qtdGrandes() * 0.60 << endl;

    return 0;
}