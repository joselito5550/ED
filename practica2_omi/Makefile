# /*
#  *  @author: Omar Sotillo i32sofro@uco.es
#  *  @date: Tuesday , 3 , Nov, 2015
#  *  @description: MAKEFILE OF FIRST LESSON
#  *  @github: https://github.com/omarsotillo/software-engineering-omar
#  */
CFLAGS := -g -std=c++11 -Wall
OBJECTMAIN := ./build/customlist.o ./build/donor.o ./build/donors.o ./build/main.o


 all: ./bin/main  clean
# MAIN FILE
./build/main.o : ./src/main.cpp
	@echo "\033[93m Main.o";
	@echo "\033[95m Creating the main.o file.";g++ $(CFLAGS) ./src/main.cpp -c -o ./build/main.o

./build/donor.o : ./src/donor.cpp
	@echo "\033[93m donor.o";
	@echo "\033[95m Creating the donor.o file.";g++ $(CFLAGS) ./src/donor.cpp -c -o ./build/donor.o

./build/donors.o : ./src/donors.cpp
	@echo "\033[93m donors.o";
	@echo "\033[95m Creating the donors.o file.";g++ $(CFLAGS) ./src/donors.cpp -c -o ./build/donors.o

./build/customlist.o : ./src/customlist.cpp
	@echo "\033[93m donors.o";
	@echo "\033[95m Creating the customlist.o file.";g++ $(CFLAGS) ./src/customlist.cpp -c -o ./build/customlist.o

./bin/main : $(OBJECTMAIN)
	@echo "\033[92m Compiling into main executable."; g++ $(CFLAGS) $(OBJECTMAIN) -o ./bin/main

clean: $(OBJECTMAIN)
	@echo "\033[91m Removing objects files.";rm -f $(OBJECTMAIN)