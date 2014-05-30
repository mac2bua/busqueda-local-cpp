#include <cassert>
#include <algorithm>
#include "grafo.h"

Grafo::Grafo(int cantNodos) : Grafo() {
	for (int i = 0; i < cantNodos; i++) {
		this->agregarNodo();
	}
}

int Grafo::cantNodos() const {
	return _adyacencias.size();
}

int Grafo::cantAristas() const {
	return _n_aristas;
}

int Grafo::agregarNodo() {
	_adyacencias.push_back(Vecinos());
	return cantNodos() - 1;
}

void Grafo::agregarArista(int id1, int id2) {
<<<<<<< HEAD
	assert(cantNodos() > std::max(id1, id2));
	_adyacencias[id1].push_back(id2);
	_adyacencias[id2].push_back(id1);
=======
	assert(_nodos.size() > id1 && _nodos.size() > id2);
	_nodos[id1]._vecinos.push_back(id2);
	_nodos[id2]._vecinos.push_back(id1);
>>>>>>> ba6315c2468813a51caa856a922e07c5539bfc38
	_n_aristas++;
}

const Grafo::Vecinos Grafo::vecinos(int nodo) const {
  return _adyacencias[nodo];
}

Grafo::Nodos Grafo::nodos() const {
  vector<Nodo> v(cantNodos());
  iota(v.begin(), v.end(), 0);
  return v;
}
<<<<<<< HEAD
=======

void Grafo::IteradorNodos::avanzar() {
	_indice_actual++;
}

Grafo::IteradorVecinos Grafo::vecinos(int nodo) const {
	return IteradorVecinos(*this, nodo);
}

bool Grafo::IteradorVecinos::haySiguiente() {
	return _indice_actual < (((_grafo->_nodos)[_nodo])._vecinos).size();
}

int Grafo::IteradorVecinos::siguiente() {
	return (((_grafo->_nodos)[_nodo])._vecinos)[_indice_actual];
}

void Grafo::IteradorVecinos::avanzar() {
	_indice_actual++;
}
>>>>>>> ba6315c2468813a51caa856a922e07c5539bfc38
