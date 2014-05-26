#include "grafo.h"
#include "camino.h"

class EstrategiaDeBusqueda {
	
public:

	EstrategiaDeBusqueda(Grafo& g);
	const IteradorVecindad vecindadSolucionActual() const;
	void cambiarSolucionActual(CaminoSimple& c);

	class IteradorVecindad {

	public:
		bool haySiguiente();
		CaminoSimple& siguiente();
		void avanzar();

	private:
		IteradorVecindad(CaminoSimple& c);
		friend typename EstrategiaDeBusqueda::vecindadSolucionActual() const;
	};

private:

	CaminoSimple* _solucion_actual;
};