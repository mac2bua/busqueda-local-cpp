

class BusquedaLocal {

public:
	BusquedaLocal(Grafo& g);
	void iniciar(Solucion& inicial);
 	Solucion& solucionActual();
	Costo costoSolucionActual();
	

private:
	Grafo* g;
	Solucion* solucion_actual;
	int n_iteracion;
};

