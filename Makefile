#
# Makefile voor Project Euler
#
# Sander in 't Veld, mei 2013
#


# onze programmas
P = euler

# object files
O1 = main.o old_main.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = -lpthread

# make
current: main.o
	gcc main.o -o $(P) $(LFLAGS)

old: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c

old_main.o: old_main.c
	gcc -c $(CFLAGS) old_main.c

# clean
clean:
	rm -f $(O1)
	rm -f $(P)

realclean:
	rm -f $(O1)
	rm -f $(P)
	rm -f *~
	
