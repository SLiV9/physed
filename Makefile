#
# Makefile voor Project Euler
#
# Sander in 't Veld, mei 2013
#


# onze programmas
P = euler

# object files
O1 = old_main.o problem2.o problem3.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
old: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
old_main.o: old_main.c
	gcc -c $(CFLAGS) old_main.c
	
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
	
