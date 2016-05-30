# /*
#  *  @author: Omar Sotillo i32sofro@uco.es
#  *  @date: Tuesday , 3 , Nov, 2015
#  *  @description: MAKEFILE OF FIRST LESSON
#  *  @github: https://github.com/omarsotillo/software-engineering-omar
#  */
CFLAGS := -g -std=c++11 -Wall
OBJECTMAIN :=  ./build/algorithms.o ./build/graph_matrix.o ./build/in_out.o ./build/main.o


 all: ./bin/main  clean
# MAIN FILE
./build/main.o : ./src/main.cpp ./include/all.hpp
	@echo "\033[93m Main.o";
	@echo "\033[95m Creating the main.o file.";g++ $(CFLAGS) ./src/main.cpp -c -o ./build/main.o

./build/algorithms.o : ./src/algorithms.cpp ./include/all.hpp
	@echo "\033[93m algorithms.o";
	@echo "\033[95m Creating the algorithms.o file.";g++ $(CFLAGS) ./src/algorithms.cpp -c -o ./build/algorithms.o

./build/graph_matrix.o : ./src/graph_matrix.cpp ./include/libraries.hpp
	@echo "\033[93m graph_matrix.o";
	@echo "\033[95m Creating the graph_matrix.o file.";g++ $(CFLAGS) ./src/graph_matrix.cpp -c -o ./build/graph_matrix.o

./build/in_out.o : ./src/in_out.cpp ./include/libraries.hpp
	@echo "\033[93m in_out.o";
	@echo "\033[95m Creating the in_out.o file.";g++ $(CFLAGS) ./src/in_out.cpp -c -o ./build/in_out.o


./bin/main : $(OBJECTMAIN)
	@echo "\033[92m Compiling into main executable."; g++ $(CFLAGS) $(OBJECTMAIN) -o ./bin/main

clean: $(OBJECTMAIN)
	@echo "\033[91m Removing objects files.";rm -f $(OBJECTMAIN)
