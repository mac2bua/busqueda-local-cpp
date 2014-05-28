#include "estregia.h"

EstrategiaDeBusqueda::EstrategiaDeBusqueda(Grafo& g) {
	calcularSolucionInicial(g);
}

const CaminoSimple& solucionActual() const {
	return *_solucion_actual;
}

const CaminoSimple& EstrategiaDeBusqueda::solucionInicial(Grafo& g) {
	Grafo::IteradorVecino iter = g.vecinos(0);
	CaminoSimple c = new CaminoSimple(0);
	while(iter.tieneProximo()) {
		if(c.agregarNodo(iter.proximo())){ 
			iter = g.vecinos(iter.proximo());
		}
	}
	_solucion_actual = c;
	_grafo = g;
}

const Grafo& grafo() const {
	return *_grafo;
}

EstrategiaDeBusqueda::IteradorVecindad EstrategiaDeBusqueda::vecindadSolucionActual() const {
	return IteradorVecindad(*_solucion_actual);
}

bool EstrategiaDeBusqueda::IteradorVecindad::haySiguiente() const {
	return _indice < _solucion_actual.tamanio();
}

CaminoSimple& EstrategiaDeBusqueda::IteradorVecindad::siguiente() {
	return _vecino_actual;
}

void EstrategiaDeBusqueda::IteradorVecindad::avanzar() {
	_indice++;
	CaminoSimple* vecino = new CaminoSimple(_solucion_actual);
	while (vecino->nodos() > _indice+1) {
		vecino->borrarUltimo();
	}
	const Grafo& g = estrategia.grafo();
	Grafo::IteradorVecino iter = g.vecinos(_solucion_actual.iesimo(_indice));
	while(iter.tieneProximo()) {
		if(vecino->agregarNodo(iter.proximo())){ 
			iter = g.vecinos(iter.proximo());
		}
	}

	_vecino_actual = vecino;
}