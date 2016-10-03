CC=gcc
CCFLAGS=-m32 -std=c99 -Wall -Werror -pedantic -I.

maze: mazerunner.o mazeutils.o display.o
	$(CC) $(CCFLAGS) -lcurses mazerunner.o mazeutils.o display.o -o maze

clean:
	cp display.o display.asdfasdf
	rm -rf *.o spec_calc calc a.out driver1 driver2 driver3 driver4
	mv display.asdfasdf display.o
