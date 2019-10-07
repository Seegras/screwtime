
CFLAGS=-O2 -Wall -fPIC
CC=gcc

all: screwtime.so testtime 

screwtime.so: screwtime.c
	$(CC) $(CFLAGS) -c screwtime.c -o screwtime.o
	ld -shared -o screwtime.so screwtime.o -ldl

testtime: testtime.c
	$(CC) $(CFLAGS) testtime.c -o testtime 
	strip testtime

clean:
	rm -f core *.o screwtime.so testtime
