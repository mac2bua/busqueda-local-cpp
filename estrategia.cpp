#include "estregia.h"

EstrategiaDeBusqueda::EstrategiaDeBusqueda(Grafo& g) {
	calcularSolucionInicial(g);
}

Camino EstrategiaDeBusqueda::solucionInicial(Grafo& g) {
	Grafo::IteradorVecino iter = g.vecinos(0);
	CaminoSimple c = new CaminoSimple(0);
	while(iter.tieneProximo()) {
		if(c.agregarNodo(iter.proximo())){ 
			iter = g.vecinos(iter.proximo());
		}
	}
	_solucion_actual = c;
}

const IteradorVecindad EstrategiaDeBusqueda::vecindadSolucionActual() const {
	return IteradorVecindad(*_solucion_actual);
}

void cambiarSolucionActual(CaminoSimple& c) {	
	_solucion_actual = c;
}
