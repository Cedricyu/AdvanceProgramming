CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

OBJS = main.o robot.o maze.o

output: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o output

clean:
	rm -f *.o output
