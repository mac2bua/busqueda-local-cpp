#include <iostream>
#include "grafo.h"
#include "caminosimple.h"
#include "estrategia.h"

using namespace std;


int main() {

	int n, m, n1, n2, cantGrafos;

	cin >> cantGrafos;

	while (cantGrafos--) {

		/** cargo el grafo (idealmente desde un archivo) **/

		cin >> n;
		Grafo g(n);

		cin >> m;
		while (m--) {
			cin >> n1 >> n2;
			g.agregarArista(n1, n2);
		}

		EstrategiaDeBusqueda estrategia(g);
		const CaminoSimple* mejorAnterior = &(estrategia.solucionActual());

		do {
			
			EstrategiaDeBusqueda::IteradorVecindad iterador = estrategia.vecindadSolucionActual();
			while(iterador.haySiguiente()) {
				if(iterador.siguiente().cantNodos() > estrategia.solucionActual().cantNodos()) {
					mejorAnterior = &(estrategia.solucionActual());
					estrategia.cambiarSolucionActual(iterador.siguiente());
				}
				iterador.avanzar();
			}


		} while (estrategia.solucionActual() != *mejorAnterior);

		cout << estrategia.solucionActual() << endl;

	}


	

	return 0;

}
