#include <vector>


class Grafo {

public:

	class IteradorNodos;
	class IteradorVecinos;

	Grafo();
	Grafo(int cantNodos);
	~Grafo();
	int cantNodos() const;
	int cantAristas() const;
	int agregarNodo();
	void agregarArista(int id1, int id2);
	IteradorNodos nodos() const;
	IteradorVecinos vecinos(int id) const;

	class IteradorNodos {

	public:
		bool haySiguiente();
		int siguiente();
		void avanzar();

	private:
		const Grafo& _grafo;
		int _indice_actual;

		IteradorNodos(const Grafo& g, int i = 0) : _grafo(g), _indice_actual(i) {};
		friend typename Grafo::IteradorNodos Grafo::nodos() const;
	};

	class IteradorVecinos {

	public:
		bool haySiguiente();
		int siguiente();
		void avanzar();

	private:
		const Grafo& _grafo;
		int _nodo;
		int _indice_actual;
	
		IteradorVecinos(const Grafo& g, int nodo, int i = 0) : _grafo(g), _nodo(nodo), _indice_actual(i) {};
		friend typename Grafo::IteradorVecinos Grafo::vecinos(int id) const;
	};

private:

	struct Nodo {
		int _id;
		std::vector<Nodo*>* _vecinos;
		Nodo(int i) {
			_id = i;
			_vecinos = new std::vector<Nodo*>();
		} 
	};

	void inicializar();

	std::vector<Nodo*> *_nodos;
	int _n_nodos;
	int _n_aristas;
};

