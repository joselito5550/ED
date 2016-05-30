#include <cstdlib>
#include <iostream>

#include "../include/all.hpp"

void printmenu();

int  main() {
  int option = 1;
  edi::GraphMatrix *g;
  bool isLoaded = false;

  while (option) {
    printmenu();

    do std::cin >> option;
    while (option < 0 or option > 10);

    switch (option) {
    case 0: {
      std::cout << "\n";
      exit(EXIT_SUCCESS);
    }

    case 1: {
      BORRAR;
      std::string fileGraph;

          LUGAR(8, 11);
      INTENSIDAD;
      std::cout << WARNING << "Introduce the name of the file." <<
      std::endl << ENDC;

          LUGAR(9, 11);
      std::cin >> fileGraph;
      isLoaded = loadGraph(g, fileGraph);

      if (not isLoaded) {
          LUGAR(8, 11);
        INTENSIDAD;
        std::cout << WARNING << "Error loading the file." <<
        std::endl << ENDC;
      }
      break;
    }

    case 2: {
      BORRAR;

      if (isLoaded) {
        float **distance = (float **)malloc(g->numVertexes() * sizeof(float *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          distance[i] = (float *)malloc(g->numVertexes() * sizeof(float));
        }
        int **intermediate = (int **)malloc(g->numVertexes() * sizeof(int *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          intermediate[i] = (int *)malloc(g->numVertexes() * sizeof(int));
        }
        g->beginVertex();
        LUGAR(8, 11);

        FloydAlgorithm(*g, distance, intermediate);
        VertexSmaller(*g, distance);
      } else {
        LUGAR(8, 11);
        INTENSIDAD;
        std::cout << FAIL << "Please load a graph." <<
        std::endl << ENDC;
      }
      break;
    }

    case 3: {
      BORRAR;

      if (isLoaded) {
        showGraph(*g);
      } else {
        LUGAR(8, 11);
        INTENSIDAD;
        std::cout << FAIL << "Please load a graph." <<
        std::endl << ENDC;
      }
      break;
    }

    case 4: {
      BORRAR;
      int suma = 0;

      if (isLoaded) {
        float **distance = (float **)malloc(g->numVertexes() * sizeof(float *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          distance[i] = (float *)malloc(g->numVertexes() * sizeof(float));
        }
        int **intermediate = (int **)malloc(g->numVertexes() * sizeof(int *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          intermediate[i] = (int *)malloc(g->numVertexes() * sizeof(int));
        }
        g->beginVertex();

        do
        {
          std::cout << "\n     " << g->currVertex().getData();
          g->nextVertex();
        } while (not g->afterEndVertex());
        std::cout << std::endl<<std::endl;
        edi::Vertex v;

        for (size_t i = 0; i < g->numVertexes(); i++) {
          g->goTo(i);
          v = g->currVertex();
          FloydAlgorithm(*g, distance, intermediate);
          suma = addDistances(*g, distance, v);
          std::cout << OKGREEN << "The addiction for the vertex  " <<
          v.getData() << " is " << WARNING <<
          suma << std::endl;
        }
      } else {
          LUGAR(8, 11);
        INTENSIDAD;
        std::cout << FAIL << "Please load a graph." <<
        std::endl << ENDC;
      }
      break;
    }

    case 5: {
      BORRAR;

      if (isLoaded) {
        float **distance = (float **)malloc(g->numVertexes() * sizeof(float *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          distance[i] = (float *)malloc(g->numVertexes() * sizeof(float));
        }
        int **intermediate = (int **)malloc(g->numVertexes() * sizeof(int *));

        for (size_t i = 0; i < g->numVertexes(); i++) {
          intermediate[i] = (int *)malloc(g->numVertexes() * sizeof(int));
        }
        std::string data;
        g->beginVertex();
        std::cout << std::endl;
          LUGAR(13, 11);
        INTENSIDAD;
        std::cout << OKBLUE << "Introduce the origin vertex." <<
        std::endl << ENDC;
          LUGAR(14, 11);
        std::cin >> data;
        g->searchVertex(data);

        while (not g->hasCurrVertex()) {
          BORRAR;
          LUGAR(10, 11);
          INTENSIDAD;
          std::cout << FAIL <<
          "Vertex dont exists, please introduce a correct one." <<
          std::endl << ENDC;
          LUGAR(11, 11);
          std::cin >> data;
          g->searchVertex(data);
        }
        edi::Vertex from = g->currVertex();
          LUGAR(15, 11);
        INTENSIDAD;
        std::cout << OKBLUE << "Introduce the end vertex." <<
        std::endl << ENDC;
          LUGAR(16, 11);
        std::cin >> data;
        g->searchVertex(data);

        while (not g->hasCurrVertex()) {
          BORRAR;
          LUGAR(8, 11);
          INTENSIDAD;
          std::cout << FAIL <<
          "Vertex dont exists, please introduce a correct one." <<
          std::endl << ENDC;
          LUGAR(9, 11);
          std::cin >> data;
          g->searchVertex(data);
        }
        edi::Vertex to = g->currVertex();
        FloydAlgorithm(*g, distance, intermediate);
        shortestPath(*g,
                     (const float **)distance,
                     (const int **)intermediate,
                     from,
                     to);
      } else {
        LUGAR(8, 11);
        INTENSIDAD;
        std::cout << FAIL << "Please load a graph." <<
        std::endl << ENDC;
      }
      break;
    }
    }
    getchar();
    getchar();
  }
}

void printmenu() {
  BORRAR;

  // Welcoming the user to the main.
  LUGAR(4, 10);
  INTENSIDAD;
  SUBRAYADO;
  std::cout << HEADER << "Welcome to the 4º Work of ED!" << std::endl << ENDC;

  // Showing the menu
  LUGAR(6, 10);
  APAGA;
  std::cout << OKBLUE << "Please choose and option from the menu:" <<
  std::endl << ENDC;

  LUGAR(8, 11);
  INTENSIDAD;
  std::cout << "1.- ";
  APAGA;
  std::cout << WARNING << "Load a graph from a file." <<
  std::endl << ENDC;
  LUGAR(9, 11);
  INTENSIDAD;
  std::cout << "2.- ";
  APAGA;
  std::cout << WARNING << "Vertex with the lowest distance" <<
  std::endl << ENDC;
  LUGAR(10, 11);
  INTENSIDAD;
  std::cout << "3.- ";
  APAGA;
  std::cout << WARNING << "Show the graph" <<
  std::endl << ENDC;
  LUGAR(11, 11);
  INTENSIDAD;
  std::cout << "4.- ";
  APAGA;
  std::cout << WARNING << "Addiction of distances." <<
  std::endl << ENDC;
  LUGAR(12, 11);
  INTENSIDAD;
  std::cout << "5.- ";
  APAGA;
  std::cout << WARNING << "shortestPath between to cities." <<
  std::endl << ENDC;
  LUGAR(14, 11);
  INTENSIDAD;
  std::cout << "0.- ";
  APAGA;
  std::cout << WARNING << "Exit" <<
  std::endl << ENDC;

  LUGAR(15, 11);
  INTENSIDAD;
  std::cout << "Introduce an option: " << std::endl;
  APAGA;
}
