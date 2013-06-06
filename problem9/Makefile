#
# Makefile voor Project Euler
#
# Sander in 't Veld, juni 2013
#


# onze programmas
P = euler

# object files
O1 = main.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
main: main.o
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c

# clean
clean:
	rm -f $(O1)
	rm -f $(P)

realclean:
	rm -f $(O1)
	rm -f $(P)
	rm -f *~
	
