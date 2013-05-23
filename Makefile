#
# Makefile voor Project Euler
#
# Sander in 't Veld, mei 2013
#


# onze programmas
P = euler

# object files
O1 = main.o problem2.o problem3.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
all: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c
	
problem2.o: problem2.c
	gcc -c $(CFLAGS) problem2.c
	
problem3.o: problem3.c
	gcc -c $(CFLAGS) problem3.c

# clean
clean:
	rm -f $(O1)
	rm -f $(P)

realclean:
	rm -f $(O1)
	rm -f $(P)
	rm -f *~
	
