#include <cassert>
#include "grafo.h"


Grafo::Grafo() {
	inicializar();
}

Grafo::Grafo(int cantNodos) {
	inicializar();
	for (int i = 0; i < cantNodos; i++) {
		this->agregarNodo();
	}
}

void Grafo::inicializar() {
	_nodos = new std::vector<Nodo*>();
	_n_nodos = 0;
	_n_aristas = 0;
}

Grafo::~Grafo() {
	delete _nodos;
}

int Grafo::cantNodos() const {
	return _n_nodos;
}

int Grafo::cantAristas() const {
	return _n_aristas;
}

int Grafo::agregarNodo() {
	Nodo* nuevo = new Nodo(_n_nodos);
	_nodos->push_back(nuevo);
	_n_nodos++;
	return _n_nodos-1;
}

void Grafo::agregarArista(int id1, int id2) {
	assert(_nodos->size() > id1 && _nodos->size() > id2);
	(*_nodos)[id1]->_vecinos->push_back((*_nodos)[id2]);
	(*_nodos)[id2]->_vecinos->push_back((*_nodos)[id1]);
	_n_aristas++;
}

Grafo::IteradorNodos Grafo::nodos() const {
	return IteradorNodos(*this);
}

bool Grafo::IteradorNodos::haySiguiente() {
	return _indice_actual < _grafo._nodos->size();
}

int Grafo::IteradorNodos::siguiente() {
	return (*(*_grafo._nodos)[_indice_actual])._id;
}

void Grafo::IteradorNodos::avanzar() {
	_indice_actual++;
}

Grafo::IteradorVecinos Grafo::vecinos(int nodo) const {
	return IteradorVecinos(*this, nodo);
}

bool Grafo::IteradorVecinos::haySiguiente() {
	return _indice_actual < (*(*(*_grafo._nodos)[_nodo])._vecinos).size();
}

int Grafo::IteradorVecinos::siguiente() {
	return (*(*(*(*_grafo._nodos)[_nodo])._vecinos)[_indice_actual])._id;
}

void Grafo::IteradorVecinos::avanzar() {
	_indice_actual++;
}