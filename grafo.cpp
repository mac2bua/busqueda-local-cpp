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
  assert(cantNodos() > std::max(id1, id2));
  _adyacencias[id1].push_back(id2);
  _adyacencias[id2].push_back(id1);
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
