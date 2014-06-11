#include "caminosimple.h"
#include <cassert>
#include <iostream>

void testCrearCamino() {
 CaminoSimple cs;
 assert(cs.cantNodos() == 0);
 assert(cs.agregarNodo(1));
 assert(cs.cantNodos() == 1);

 std::cout << "test crear camino simple ok" << std::endl;
}

void testCopiarCamino() {
	CaminoSimple cs;
	CaminoSimple copia1(cs);
	assert(cs.cantNodos() == copia1.cantNodos());
 	assert(cs.agregarNodo(1) == copia1.agregarNodo(1));
 	assert(cs.cantNodos() == copia1.cantNodos());

 	assert(copia1.agregarNodo(2));
 	assert(copia1.agregarNodo(4));
 	assert(copia1.agregarNodo(2) == false);

 	CaminoSimple copia2(copia1);
 	assert(copia2.cantNodos() == copia1.cantNodos());

 	for (int i = 0; i < copia1.cantNodos(); i++) {
 		assert(copia1.iesimo(i) == copia2.iesimo(i));
 	}


 	std::cout << "test copiar camino simple ok" << std::endl;
}

void testTodosDistintos() {
 CaminoSimple cs;
 for (int i = 0; i < 10; i++) {
 	assert(cs.agregarNodo(i));
 	assert(cs.cantNodos() == i+1);
 }

 std::cout << "test todos distintos ok" << std::endl;
}

void testAgregarElementosRepetidos() {
 CaminoSimple cs;
 int elems[] = {1,3,3,2,1,4,5,9,1,0,10,1,8,7,6,5};
 int results[] = {1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,0};
 int tams[] = {1,2,2,3,3,4,5,6,6,7,8,8,9,10,11,11};
 for (int i = 0; i < 16; i++) {
 	assert(cs.agregarNodo(elems[i]) == results[i]);
 	assert(cs.cantNodos() == tams[i]);
 	
 }

 std::cout << "test agregar elementos repetidos ok" << std::endl;
}

int main() {
 
 testCrearCamino();
 testCopiarCamino();
 testTodosDistintos();
 testAgregarElementosRepetidos();
 
 return 0;
}