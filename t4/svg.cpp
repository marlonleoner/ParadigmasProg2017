#include <fstream>
#include <sstream>

#include <circle.h>
#include <svg.h>

using namespace std;

GeradorSVG::GeradorSVG() {
    this->tag = "<svg height=\"600\" width=\"600\">";
}

GeradorSVG::GeradorSVG(int h, int w) {
    stringstream s;
    s << "<svg height=\"" << h << "\" width=\"" << w << "\">";
    this->tag = s.str();
}

string GeradorSVG::getTag() {
    return this->tag;
}

string GeradorSVG::imprimeLinhas(vector<Circle> c) {

    int x1, x2, y1, y2;

    stringstream svg;

    for(int i = 0 ; i < c.size() - 1 ; i++) {
        x1 = c[i].getCentro().getX();
        y1 = c[i].getCentro().getY();
        x2 = c[i+1].getCentro().getX();
        y2 = c[i+1].getCentro().getY();

        svg << "\t<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>" << endl;

    }

    x1 = c[c.size() - 1].getCentro().getX();
    y1 = c[c.size() - 1].getCentro().getY();
    x2 = c[0].getCentro().getX();
    y2 = c[0].getCentro().getY();

    svg << "\t<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>" << endl;

    return svg.str();
}

string GeradorSVG::imprimeCirculo(vector<Circle> c) {

    stringstream svg;

    for(int i = 0 ; i < c.size() ; i++) {
        svg << "\t<circle cx=\"" << c[i].getCentro().getX() << "\" cy=\"" << c[i].getCentro().getY() << "\" r=\"" << c[i].getRaio() << "\" stroke=\"black\" stroke-width=\"3\" fill=\"none\"/>" << endl;
    }

    return svg.str();
}

void GeradorSVG::imprimeSVG(vector<Circle> c) {

    ofstream svg;

    svg.open("circulos.svg");

    svg << this->getTag() << endl;

    svg << this->imprimeCirculo(c) << endl;

    svg << this->imprimeLinhas(c) << endl;

    svg << "</svg>" << endl;

    svg.close();
}