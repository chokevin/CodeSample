CCC = g++
CCFLAGS = -ansi

monopoly: driver1.o player.o game.o property.o
	$(CCC) -o monopoly driver1.o player.o game.o property.o

driver1.o:

player.o: player.h

property.o: property.h

game.o: game.h player.h property.h 

clean:
	rm -f *.o

real_clean: clean
	rm -f monopoly
