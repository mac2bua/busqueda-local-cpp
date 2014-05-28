#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <vector>
#include "grafo.h"
#include "caminosimple.h"

class EstrategiaDeBusqueda {
	
public:

	class IteradorVecindad;

	EstrategiaDeBusqueda(Grafo& g);
	const CaminoSimple& solucionActual() const;
	IteradorVecindad vecindadSolucionActual() const;
	void cambiarSolucionActual(CaminoSimple& c);
	const Grafo& grafo() const;

	class IteradorVecindad {

	public:
		bool haySiguiente() const;
		CaminoSimple& siguiente();
		void avanzar();

	private:

		EstrategiaDeBusqueda& _estrategia;
		const CaminoSimple& _actual;
		int _indice;
		CaminoSimple* _vecino_actual;

		IteradorVecindad(EstrategiaDeBusqueda& edb) : _estrategia(edb), _actual(edb.solucionActual()), _indice(0), _vecino_actual(NULL) {}
		friend typename EstrategiaDeBusqueda::IteradorVecindad EstrategiaDeBusqueda::vecindadSolucionActual() const;
	};

private:
	Grafo* _grafo;
	CaminoSimple* _solucion_actual;
};

#endif