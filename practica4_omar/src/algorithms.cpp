#include "../include/all.hpp"


int addDistances(edi::GraphMatrix& g, float **distance, edi::Vertex v) {
  int add = 0;

  // Hacemos un recorrido desde el vertice v a todos sumando las distancias
  for (size_t i = 0; i < g.numVertexes(); i++) {
    add += distance[v.getLabel()][i];
  }
  return add;
}

void VertexSmaller(edi::GraphMatrix& g, float **distanceM){
	double smaller_distance = INFINITE;
	int vertex;
	double distance = 0;
	for(size_t i=0;i<g.numVertexes();i++){
		for(size_t j = 0;j<g.numVertexes();j++){
			distance += distanceM[i][j];
		}
		if(distance < smaller_distance){
			smaller_distance = distance;
			vertex = i;
		}
		distance = 0;
	}
	g.goTo(vertex);
	edi::Vertex v = g.currVertex();
	std::cout<<OKGREEN<<"The smaller distance is : "<<smaller_distance<<std::endl;;
	std::cout<<WARNING<<"The vertex is: "<<v.getData();
	getchar();
}

void FloydAlgorithm(edi::GraphMatrix& g, float **distance, int **intermediate) {
  for (size_t i = 0; i < g.numVertexes(); i++) {
    g.goTo(i);
    edi::Vertex u = g.currVertex();

    for (size_t j = 0; j < g.numVertexes(); j++) {
      g.goTo(j);
      edi::Vertex v = g.currVertex();
      distance[i][j] = g.adjacent(u, v);
    }
  }

  for (size_t i = 0; i < g.numVertexes(); i++) {
    for (size_t j = 0; j < g.numVertexes(); j++) {
      intermediate[i][j] = j;
    }
  }

  for (size_t k = 0; k < g.numVertexes(); k++) {
    for (size_t i = 0; i < g.numVertexes(); i++) {
      for (size_t j = 0; j < g.numVertexes(); j++) {
        if (distance[i][k] + distance[k][j] < distance[i][j]) {
          distance[i][j]     = distance[i][k] + distance[k][j];
          intermediate[i][j] = intermediate[i][k];
        }
      }
    }
  }
}

void shortestPath(edi::GraphMatrix & g,
                  const float      **distance,
                  const int        **intermediate,
                  const edi::Vertex& from,
                  const edi::Vertex& to) {
  std::cout << "\n     The shortestPath between  " << from.getData() <<
  " and " <<
  to.getData() << " is \e[92m" << distance[from.getLabel()][to.getLabel()] <<
  "\e[0m\n";
  std::cout << "\n     The shortestPath to arrive from " <<
  from.getData() << " to " << to.getData() << " is\n\n     ";
  std::cout << "\e[94m" << from.getData() << "\e[0m\t->\n     ";
  int currentLabel = from.getLabel();

  while (to.getLabel() != intermediate[currentLabel][to.getLabel()]) {
    g.goTo(intermediate[currentLabel][to.getLabel()]);
    std::cout << "\e[95m" << g.currVertex().getData() << "\e[0m\t->\n     ";
    currentLabel = intermediate[currentLabel][to.getLabel()];
  }
  std::cout << "\e[91m" << to.getData() << "\e[0m\t**" << std::endl;
}
