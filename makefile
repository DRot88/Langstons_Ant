#CC will be compiler to use
#CFLAGS will be options to pass
#SOURCES will be cpp files
#OBJECTS will be .o files
#EXECUTABLE will be completed program
# -c creates object files/does not link
# -g for debugging information
# -Wall for all warnings
CC = g++
STD = -std=c++0x
CFLAGS = -g -Wall
SOURCES = main.cpp playAntGame.cpp printBoard.cpp menu.cpp ant.cpp validation.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = project1


all: $(EXECUTABLE)

project1: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(STD) -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS) $(STD) -c

playAntGame.o: playAntGame.cpp
	$(CC) playAntGame.cpp $(CFLAGS) $(STD) -c

printBoard.o: printBoard.cpp
	$(CC) printBoard.cpp $(CFLAGS) $(STD) -c

menu.o: menu.cpp
	$(CC) menu.cpp $(CFLAGS) $(STD) -c

ant.o: ant.cpp
	$(CC) ant.cpp $(CFLAGS) $(STD) -c		

validation.o: validation.cpp
	$(CC) validation.cpp $(CFLAGS) $(STD) -c

clean:
	rm *o $(EXECUTABLE)
