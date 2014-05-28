#include "busquedalocal.h"
#include "grafo.h"

BusquedaLocal::BusquedaLocal(Grafo& g) {
	this->grafo = new Grafo(g);
}
