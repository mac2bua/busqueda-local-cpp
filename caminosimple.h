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
	std::ostream& mostrarCamino(std::ostream& os) const;


private:
	std::set<int> _nodos;
	std::vector<int> _camino;
   	int _tam;
};

std::ostream& operator<<(std::ostream& os, const CaminoSimple& cs);
bool operator==(const CaminoSimple& cs1, const CaminoSimple& cs2);
bool operator!=(const CaminoSimple& cs1, const CaminoSimple& cs2);


#endif