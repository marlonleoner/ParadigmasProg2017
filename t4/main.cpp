/*************************************************

Compilar:

g++ -o p main.cpp svg.cpp circle.cpp point.cpp -I.


*************************************************/

#include <cstdlib>
#include <vector>

#include <point.h>
#include <circle.h>
#include <svg.h>

using namespace std;

int main() {

	srand(time(NULL));

	int op;
	cout << "1 - Distância entre Pontos\n2 - Distância entre Circulos\n3 - Gerar SVG\nOp: ";
	cin >> op;
	cout << "\n";

	switch(op) {

		case 1: {

			Point p = Point(10, 10);

			vector<Point*> p2;
			for(int i = 0 ; i < 5 ; i++) {
				p2.push_back(new Point(rand()%50, rand()%50));
			}

			for(int i = 0 ; i < 5 ; i++) {
				cout << "Distancia de P" << i << " - P: " << p2[i]->distanceTo(p) << endl;		
				delete p2[i];
			}

			break;
		}

		case 2: {

			Circle c1 = Circle(rand()%50, rand()%50, rand()%30);
		    Circle* c2 = new Circle(rand()%50, rand()%50, rand()%30);

		    std::cout << c1.area() << std::endl;
		    std::cout << c2->area() << std::endl;

		    cout << "Distância entre os circulos: " << c2->distanceTo(c1) << endl;

		    delete c2;

			break;
		}

		case 3: {

			vector<Circle> c;

			for(int i = 0 ; i < 10 ; i++) {

				c.push_back(Circle(rand() % 500 + 50, rand() % 500 + 50, 50));
			}

			GeradorSVG g;

			g.imprimeSVG(c);

			break;
		}

	}

}