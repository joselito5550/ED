# /*
#  *  @author: Omar Sotillo i32sofro@uco.es
#  *  @date: Tuesday , 3 , Nov, 2015
#  *  @description: MAKEFILE OF FIRST LESSON
#  *  @github: https://github.com/omarsotillo/software-engineering-omar
#  */
CFLAGS := -g -std=c++11# -Wall
OBJECTMAIN := ./build/main.o ./build/monomial.o ./build/polynomial.o


 all: ./bin/main  clean
# MAIN FILE
./build/main.o : ./src/main.cpp
	@echo "\033[93m Main.o";
	@echo "\033[95m Creating the main.o file.";g++ $(CFLAGS) ./src/main.cpp -c -o ./build/main.o

./build/monomial.o : ./src/monomial.cpp
	@echo "\033[93m monomial.o";
	@echo "\033[95m Creating the monomial.o file.";g++ $(CFLAGS) ./src/monomial.cpp -c -o ./build/monomial.o

./build/polynomial.o : ./src/polynomial.cpp
	@echo "\033[93m polynomial.o";
	@echo "\033[95m Creating the polynomial.o file.";g++ $(CFLAGS) ./src/polynomial.cpp -c -o ./build/polynomial.o

./bin/main : $(OBJECTMAIN)
	@echo "\033[92m Compiling into main executable."; g++ $(CFLAGS) $(OBJECTMAIN) -o ./bin/main

clean: $(OBJECTMAIN)
	@echo "\033[91m Removing objects files.";rm $(OBJECTMAIN)
