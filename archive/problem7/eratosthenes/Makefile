#
# Makefile voor Eratosthenes Sieve
#
# Sander in 't Veld, juni 2013
#

# programmas
P = main

# object files
O1 = main.o buffer.o sieve.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
main: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c

buffer.o: buffer.c
	gcc -c $(CFLAGS) buffer.c

sieve.o: sieve.c
	gcc -c $(CFLAGS) sieve.c

# clean
clean:
	rm -f $(O1)
	rm -f $(P)

realclean:
	rm -f $(O1)
	rm -f $(P)
	rm -f output*
	rm -f *~
