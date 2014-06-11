#include <iostream>
#include "grafo.h"
#include "caminosimple.h"


int main() {


  int n, m, n1, n2;


  // leo el grafo desde stdin
  std::cin >> n;
  Grafo g(n);
  std::cin >> m;

  while (m--) {
    std::cin >> n1 >> n2;
    g.agregarArista(n1, n2);
  }

  // std::cout << g;

  // genero solucion inicial
  CaminoSimple c;
  Grafo::Nodo v = 0;
  Grafo::Vecinos ws = g.vecinos(v);
  Grafo::IteradorVecinos iter = ws.begin();
  while (iter != ws.end()) {
    if(c.agregarNodo(*iter)) {
      ws = g.vecinos(*iter);
      iter = ws.begin();
    } else ++iter;
  }

  // std::cout << "Tamaño de camino inicial: ";
  // std::cout << c.cantNodos() << std::endl;
  // std::cout << "Camino inicial: ";
  // c.mostrarCamino(std::cout);



  int indice;

  bool hayMejora = true;
  while (hayMejora) {

    // busco en la vecindad si existe una mejor solucion
    indice = 0;
    hayMejora = false;
    while (indice < c.cantNodos()) {
      
      CaminoSimple solucionVecina(c);
      // elimino los ultimos (n-indice+1) nodos del camino
      Grafo::Nodo ultimoNodoEliminado; 
      while (solucionVecina.cantNodos() > indice+1) {
        ultimoNodoEliminado = solucionVecina.borrarUltimo();
      }

      int x = c.iesimo(indice);
      Grafo::Vecinos vs = g.vecinos(x);
      Grafo::IteradorVecinos iter = vs.begin();
      // trato de agrandar el camino a partir de "indice" pero por 
      // un nodo distinto al ultimo eliminado.
      while (iter != vs.end()) {
        if (*iter != ultimoNodoEliminado && solucionVecina.agregarNodo(*iter)) {
          ultimoNodoEliminado = -1;
          vs = g.vecinos(*iter);
          iter = vs.begin();
        } else ++iter;
      }

      // actualizo la mejor solucion
      if (solucionVecina.cantNodos() > c.cantNodos()) {
        c = solucionVecina;
        hayMejora = true;
        // std::cout << "\tTamaño de mejor vecino: ";
        // std::cout << c.cantNodos()<< std::endl;
        // std::cout << "\tMejor vecino encontrado:";
        // c.mostrarCamino(std::cout);
      }
      indice++;
    }
  }

  // por ultimo muestro la solucion encontrada
  // std::cout << "Tamaño de camino final: ";
  // std::cout << c.cantNodos() << std::endl;
  // std::cout << "Camino encontrado: ";
  c.mostrarCamino(std::cout);

  return 0;
}
