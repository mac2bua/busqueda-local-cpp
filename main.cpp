#include <iostream>
#include "grafo.h"
#include "caminosimple.h"

using namespace std;


int main() {


	int n, m, n1, n2;


	// Leo el grafo desde stdin
	cin >> n;
	Grafo g(n);

	std::cout << "grafo -> #N: " << g.cantNodos() << " #E: " << g.cantAristas() << std::endl; 

	cin >> m;
	while (m--) {
		cin >> n1 >> n2;
		g.agregarArista(n1, n2);
	}


	// Genero solucion inicial
	Grafo::IteradorVecinos iter = g.vecinos(0);
	CaminoSimple c;
	while(iter.haySiguiente()) {
		std::cout << "iter" << std::endl;
		if(c.agregarNodo(iter.siguiente())){ 
			iter = g.vecinos(iter.siguiente());
		}
		iter.avanzar();
	}

	std::cout << "camino inicial: ";
	c.mostrarCamino(cout);


	
	int _indice;

	bool hayMejora = true;
	while (hayMejora) {
	
		// busco en la vecindad si existe una mejor solucion
	   	_indice = 0;   
	   	hayMejora = false;
	   	while (_indice < c.cantNodos()) { 
			CaminoSimple vecino(c);
			while (vecino.cantNodos() > _indice+1) {
				vecino.borrarUltimo();
			}

			int x = c.iesimo(_indice);
			Grafo::IteradorVecinos iter = g.vecinos(x);
			while(iter.haySiguiente()) {
				if(vecino.agregarNodo(iter.siguiente())){ 
					iter = g.vecinos(iter.siguiente());
				}
				iter.avanzar();
			}

			// actualizo la mejor solucion
			if (vecino.cantNodos() > c.cantNodos()) {
				c = vecino;
				hayMejora = true;
				cout << "\tmejor vecino encontrado:";
				c.mostrarCamino(cout);
			}
			_indice++;
		}
	}

	// por ultimo muestro la solucion encontrada
	cout << "camino encontrado: ";
	c.mostrarCamino(cout);

	return 0;
}
