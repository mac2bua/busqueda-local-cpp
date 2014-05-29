#include <iostream>
#include "grafo.h"
#include "caminosimple.h"




int main() {


	int n, m, n1, n2;


	// Leo el grafo desde stdin
	std::cin >> n;
	Grafo g(n);
	std::cin >> m;
	

	while (m--) {
		std::cin >> n1 >> n2;
		g.agregarArista(n1, n2);
	}


	std::cout << "grafo -> #N: " << g.cantNodos() << " #E: " << g.cantAristas() << std::endl; 
	
	// Genero solucion inicial
	Grafo::IteradorVecinos iter = g.vecinos(0);
	CaminoSimple c;
	while(iter.haySiguiente()) {
	//	std::cout << "iter" << std::endl;
		if(c.agregarNodo(iter.siguiente())){ 
			iter = g.vecinos(iter.siguiente());
		}
		iter.avanzar();
	}

	std::cout << "Tamaño de camino inicial: ";
	std::cout << c.cantNodos() << std::endl;
	std::cout << "Camino inicial: ";
	c.mostrarCamino(std::cout);


	
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
				std::cout << "\tTamaño de mejor vecino: ";
				std::cout << c.cantNodos()<< std::endl;
				std::cout << "\tMejor vecino encontrado:";
				c.mostrarCamino(std::cout);
			}
			_indice++;
		}
	}

	// por ultimo muestro la solucion encontrada
	
	
	std::cout << "Tamaño de camino final: ";
	std::cout << c.cantNodos() << std::endl;
	std::cout << "Camino encontrado: ";
	c.mostrarCamino(std::cout);

	return 0;
}
