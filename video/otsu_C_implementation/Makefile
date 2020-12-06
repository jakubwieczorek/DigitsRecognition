TARGET = main.out
OBJECTS = main.o
LINK = gcc
CXX = gcc
FLAGS = -std=c99 -g -Wall -c

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) -lm
main.o: main.c seven.h 7_2.h
	$(CXX) $(FLAGS) -o main.o main.c
clean:
	rm -f *.o 
	rm *.out
