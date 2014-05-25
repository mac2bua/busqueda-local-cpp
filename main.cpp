#include <iostream>
#include "grafo.h"

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

		Camino mejorActual = caminoInicial(g);
		Camino mejorAnterior = mejorActual;

		do {
			
			IteradorVecindad iterador = vecindad(mejorActual);
			while(iterador.hayProximo()) {
				if(iterador.proximo().tamanio() > mejorActual.tamanio()) {
					mejorActual = iterador.proximo();
				}
				iterador.avanzar();
			}


		} while (mejorActual != mejorAnterior);

		cout << mejorActual << endl;

	}

	return 0;

}
