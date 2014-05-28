#ifndef CAMINO_SIMPLE_H
#define CAMINO_SIMPLE_H

#include <set>
#include <vector>
#include <iostream>

class CaminoSimple {

public:

	CaminoSimple();
	CaminoSimple(const CaminoSimple& cs);
	bool agregarNodo(int id);
	int iesimo(int i) const;
	bool incluido(int d) const;
	void borrarNodo(int id);
	void borrarUltimo();
	int cantNodos() const;
	// IteradorNodos nodos() const;
	std::ostream& mostrarCamino(std::ostream& os) const;

	// class IteradorNodos {

	// public:

	// 	bool haySiguiente() const;
	// 	int siguiente();
	// 	void avanzar();

	// private:

	// 	std::vector<int>& _nodos;
	// 	int indice;
	// 	IteradorNodos(std::vector<int>& ns, int i = 0) : _nodos(ns), indice(i) {}
	// 	friend typename CaminoSimple::nodos() const;

	// };

private:
	std::set<int>* _nodos;
	std::vector<int>* _camino;
   	int _tam;
};

#endif