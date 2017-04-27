#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef GERADOR_SVG_HEADER
#define GERADOR_SVG_HEADER

class GeradorSVG {

    private:

        string tag;

    public:

        GeradorSVG();

        GeradorSVG(int h, int w);

        string getTag();

        string imprimeLinhas(vector<Circle> c);

        string imprimeCirculo(vector<Circle> c);

        void imprimeSVG(vector<Circle> c);

};

#endif