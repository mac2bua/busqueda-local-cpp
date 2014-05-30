#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
using std::vector;

class Grafo {
public:

  typedef int Nodo;
  typedef vector<Nodo> Vecinos;
  typedef vector<Nodo> Nodos;
  typedef Nodos::const_iterator IteradorNodos;
  typedef Vecinos::const_iterator IteradorVecinos;

  Grafo() = default;
  Grafo(const Grafo& g) = default;
  Grafo(int cantNodos);
  int cantNodos() const;
  int cantAristas() const;
  int agregarNodo();
  void agregarArista(int id1, int id2);
  const Vecinos vecinos(int id) const;
  Nodos nodos() const;

private:
  std::vector<Vecinos> _adyacencias;
  int _n_aristas = 0;
};

#endif
