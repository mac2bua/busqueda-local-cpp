#include "caminosimple.h"


CaminoSimple::CaminoSimple() {
	_nodos = new std::set<int>();
	_camino = new std::vector<int>();
   	_tam = 0;
}

CaminoSimple(const CaminoSimple& cs) {
	_nodos = new std::set<int>();
	_camino = new std::vector<int>();
	for (int i = cs.nodos()-1; i >= 0; i--) {
		this->agregarNodo(cs.iesimo(i));
	}
}

bool CaminoSimple::agregarNodo(int id) {
	if (_nodos->insert(id).second) {
		_camino->push_back(id);
		_tam++;
		return true;
	}
	return false;
}

int iesimo(int i) const {
	assert(i < _camino->size());
	return _camino[i];
}

bool incluido(int id) const {
	return _nodos->find(id);
}

void borrarNodo(int id) {
	if (_nodos->find(id)) {
		_nodos->erase(id);
		std::vector<int>::iterator it = _camino->begin();
		while (*it != id) {
	    	++it;
		}
	    _camino->erase(it);
		_tam--;
	}
}

void borrarUltimo() {
	if (_tam > 0) {
		_nodos->erase(id);
		_camino->erase(_camino.end()-1);
		_tam--;
	}
}

int CaminoSimple::cantNodos() const {
	return _tam;
}

std::ostream& CaminoSimple::mostrarCamino(std::ostream& os) const {
	for (int i = 0; i < _tam; i++) {
		os << (*_camino)[i];
		if (i < _tam-1) {os << " -> ";}
	}
	return os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const CaminoSimple& cs) {
    return cs.mostrarCamino(os);
}

bool operator!=(const CaminoSimple& cs1, const CaminoSimple& cs2) {
	if (&cs1 == &cs2) return false;
	if (cs1.cantNodos() != cs2.cantNodos()) return true;
	for (int i = 0; i < cs1.cantNodos(); i++) {
		if (cs1.iesimo(i) != cs2.iesimo(i)) return true;
	}
	return false;
}

// IteradorNodos nodos() const {
// 	return IteradorNodos(*_camino);
// }

// bool CaminoSimple::IteradorNodos::haySiguiente() const {
// 	return _indice < _nodos.size();
// }

// int CaminoSimple::IteradorNodos::siguiente() {
// 	return _nodos[indice];
// }

// void CaminoSimple::IteradorNodos::avanzar() {
// 	_indice++;
// }