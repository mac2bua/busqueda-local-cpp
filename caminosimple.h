#include <set>


class CaminoSimple {

public:

	CaminoSimple();
	bool agregarNodo(int id);
	int tamanio() const;

private:
	set<int> _nodos;
	vector<int> _camino;
   	int _tam;
};