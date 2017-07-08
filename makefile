#CC will be compiler to use
#CFLAGS will be options to pass
#SOURCES will be cpp files
#OBJECTS will be .o files
#EXECUTABLE will be completed program
# -c creates object files/does not link
# -g for debugging information
# -Wall for all warnings
CC = g++
CFLAGS = -g -Wall
SOURCES = main.cpp playAntGame.cpp printBoard.cpp menu.cpp ant.cpp validation.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = project1


all: $(EXECUTABLE)

project1: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS) -c

playAntGame.o: playAntGame.cpp
	$(CC) playAntGame.cpp $(CFLAGS) -c

printBoard.o: printBoard.cpp
	$(CC) printBoard.cpp $(CFLAGS) -c

menu.o: menu.cpp
	$(CC) menu.cpp $(CFLAGS) -c

ant.o: ant.cpp
	$(CC) ant.cpp $(CFLAGS) -c		

validation.o: validation.cpp
	$(CC) validation.cpp $(CFLAGS) -c

clean:
	rm *o $(EXECUTABLE)