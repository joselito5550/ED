CFLAGS := -g -std=c++11 -Wall
OBJECTMAIN := ./build/main.o


 all: ./bin/main  clean
# MAIN FILE
./build/main.o : ./src/main.cpp ./includes/Vertice.hpp ./includes/Grafo.hpp ./includes/funciones.hpp
	@echo "\033[93m Main.o";
	@echo "\033[95m Creating the main.o file.";g++ $(CFLAGS) ./src/main.cpp -c -o ./build/main.o

./bin/main : $(OBJECTMAIN)
	@echo "\033[92m Compiling into main executable."; g++ $(CFLAGS) $(OBJECTMAIN) -o ./bin/main

clean: $(OBJECTMAIN)
	@echo "\033[91m Removing objects files.";rm $(OBJECTMAIN)
