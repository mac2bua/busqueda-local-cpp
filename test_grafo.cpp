#include <iostream>
#include <cassert>
#include "grafo.h"

void testCrearGrafo() {
	Grafo g;
	assert(g.cantNodos() == 0);
	assert(g.cantAristas() == 0);

	Grafo g2(0);
	assert(g2.cantNodos() == 0);
	assert(g2.cantAristas() == 0);

	Grafo g3(10);
	assert(g3.cantNodos() == 10);
	assert(g3.cantAristas() == 0);

	std::cout << "test crear grafo ok" << std::endl;
}

void testAgregarNodo() {

	Grafo g;
	assert(g.cantNodos() == 0);
	assert(g.cantAristas() == 0);
	
	g.agregarNodo();
	assert(g.cantNodos() == 1);
	assert(g.cantAristas() == 0);

	g.agregarNodo();
	g.agregarNodo();
	assert(g.cantNodos() == 3);
	assert(g.cantAristas() == 0);

	Grafo g2(10);
	assert(g2.cantNodos() == 10);
	assert(g2.cantAristas() == 0);

	g2.agregarNodo();
	assert(g2.cantNodos() == 11);
	assert(g2.cantAristas() == 0);

	g2.agregarNodo();
	g2.agregarNodo();
	assert(g2.cantNodos() == 13);
	assert(g2.cantAristas() == 0);


	std::cout << "test agregar nodo ok" << std::endl;
}

void testAgregarArista() {

	Grafo g;
	assert(g.cantNodos() == 0);
	assert(g.cantAristas() == 0);
	
	g.agregarArista(g.agregarNodo(), g.agregarNodo());
	assert(g.cantNodos() == 2);
	assert(g.cantAristas() == 1);

	g.agregarArista(g.agregarNodo(), g.agregarNodo());
	assert(g.cantNodos() == 4);
	assert(g.cantAristas() == 2);

	Grafo g2(10);
	assert(g2.cantNodos() == 10);
	assert(g2.cantAristas() == 0);

	g2.agregarArista(1, 9);
	assert(g2.cantNodos() == 10);
	assert(g2.cantAristas() == 1);

	g2.agregarArista(2,3);
	assert(g2.cantNodos() == 10);
	assert(g2.cantAristas() == 2);

	std::cout << "test agregar arista ok" << std::endl;
}

void testIterarNodos() {

	Grafo g;
	g.agregarArista(g.agregarNodo(), g.agregarNodo());
	g.agregarArista(g.agregarNodo(), g.agregarNodo());
	g.agregarNodo();
	g.agregarArista(4, 3);

  Grafo::Nodos ns = g.nodos();
	Grafo::IteradorNodos it = ns.begin();
	int cantNodos = 0;
	while(it != ns.end()) {
		++it;
		cantNodos++;
	}
	assert(cantNodos == 5);

	std::cout << "test iterar nodos ok" << std::endl;
}

void testIterarVecinos() {

	Grafo g2(10);
  Grafo::Nodos nodos = g2.nodos();
	Grafo::IteradorNodos it2 = nodos.begin();
	while(it2 != nodos.end()) {
    Grafo::Vecinos ws = g2.vecinos(*it2);
		Grafo::IteradorVecinos itVecinos = ws.begin();;
		assert(itVecinos == ws.end());
		++it2;
	}

	g2.agregarArista(1,2);
	g2.agregarArista(2,3);
	
  Grafo::Nodos nodos2 = g2.nodos();
	Grafo::IteradorNodos it3 = nodos2.begin();
	int cantAdyacencias = 0;
	while(it3 != nodos2.end()) {
    Grafo::Vecinos ws = g2.vecinos(*it3);
		Grafo::IteradorVecinos itVecinos2 = ws.begin();
		while(itVecinos2 != ws.end()) {
			++itVecinos2;
			cantAdyacencias++;
		}
		++it3;
	}

	assert((cantAdyacencias/2) == g2.cantAristas());
	assert(g2.cantAristas() == 2);
	std::cout << "test iterar vecinos ok" << std::endl;
}

int main() {

	testCrearGrafo();
	testAgregarNodo();
	testAgregarArista();
	testIterarNodos();
	testIterarVecinos();

	return 0;
}
