CFLAGS := -g -std=c++11# -Wall
OBJECTMAIN := ./build/main_polinomio.o ./build/monomio.o ./build/polinomio.o

all: ./bin/main_polinomio clean
# MAIN FILE
./build/main_polinomio.o : ./src/main_polinomio.cpp
	@echo "\0033[93m Main.o";
	@echo "\0033[93m Creating the main.o file.";
	g++ $(CFLAGS) ./src/main_polinomio.cpp -c -o ./build/main_polinomio.o

./build/monomio.o : ./src/Monomio.cpp
	@echo "\0033[93m Monomio.o";
	@echo "\0033[93m Creating the Monomio.o file.";
	g++ $(CFLAGS) ./src/Monomio.cpp -c -o ./build/monomio.o

./build/polinomio.o : ./src/Polinomio.cpp
	@echo "\0033[93m Polinomio.o";
	@echo "\0033[93m Creating the Polinomio.o file.";
	g++ $(CFLAGS) ./src/Polinomio.cpp -c -o ./build/polinomio.o

./bin/main_polinomio: $(OBJECTMAIN)
	@echo "\033[92m Compiling into main executable."
	g++ $(CFLAGS) $(OBJECTMAIN) -o ./bin/main_polinomio

clean: $(OBJECTMAIN)
	@echo "\033[91m Removing objects files."
	rm $(OBJECTMAIN)
