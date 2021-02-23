
maze: maze.o mazeMODS.o
	gcc -o maze maze.o mazeMODS.o

maze.o: maze.c
	gcc -c maze.c

mazeMODS.o: mazeMODS.c
	gcc -c mazeMODS.c

clean:
	rm *.o maze
