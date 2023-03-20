CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

OBJS = main.o robot.o maze.o

output: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o output

main.o: main.cpp robot.h maze.h
	$(CC) $(CFLAGS) -c main.cpp

robot.o: robot.cpp robot.h
	$(CC) $(CFLAGS) -c robot.cpp

maze.o: maze.cpp maze.h
	$(CC) $(CFLAGS) -c maze.cpp

clean:
	rm -f *.o output
