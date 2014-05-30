#include <iostream>
#include "grafo.h"
#include "caminosimple.h"


int main() {


  int n, m, n1, n2;


  // Leo el grafo desde stdin
  std::cin >> n;
  Grafo g(n);
  std::cin >> m;

  while (m--) {
    std::cin >> n1 >> n2;
    g.agregarArista(n1, n2);
  }


  std::cout << g;

  // Genero solucion inicial
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

  std::cout << "Tamaño de camino inicial: ";
  std::cout << c.cantNodos() << std::endl;
  std::cout << "Camino inicial: ";
  c.mostrarCamino(std::cout);



  int _indice;

  bool hayMejora = true;
  while (hayMejora) {

    // busco en la vecindad si existe una mejor solucion
      _indice = 0;
      hayMejora = false;
      while (_indice < c.cantNodos()) {
      CaminoSimple vecino(c);
      while (vecino.cantNodos() > _indice+1) {
        vecino.borrarUltimo();
      }

      int x = c.iesimo(_indice);
      Grafo::Vecinos ws = g.vecinos(x);
      Grafo::IteradorVecinos iter = ws.begin();
      while (iter != ws.end()) {
        if (vecino.agregarNodo(*iter)) {
          ws = g.vecinos(*iter);
          iter = ws.begin();
        } else ++iter;
      }

      // actualizo la mejor solucion
      if (vecino.cantNodos() > c.cantNodos()) {
        c = vecino;
        hayMejora = true;
        std::cout << "\tTamaño de mejor vecino: ";
        std::cout << c.cantNodos()<< std::endl;
        std::cout << "\tMejor vecino encontrado:";
        c.mostrarCamino(std::cout);
      }
      _indice++;
    }
  }

  // por ultimo muestro la solucion encontrada


  std::cout << "Tamaño de camino final: ";
  std::cout << c.cantNodos() << std::endl;
  std::cout << "Camino encontrado: ";
  c.mostrarCamino(std::cout);

  return 0;
}
