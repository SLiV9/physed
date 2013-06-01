#
# Makefile voor Project Euler
# Probleem 7
#
# Sander in 't Veld, mei 2013
#


# onze programmas
P = euler

# object files
O1 = main.o genny.o buffer.o sieve.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
main: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c

genny.o: genny.c
	gcc -c $(CFLAGS) genny.c

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
	rm -f *~
	
