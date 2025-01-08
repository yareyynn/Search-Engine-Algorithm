CC = gcc
CFLAGS = -Wall -std=c99

SOURCES = alice.c bob.c q1/a.c q1/b.c q2/a.c q2/b.c q2/c.c q2/d.c q2/e.c q3/a.c q3/b.c q4/a.c q4/b.c
OBJECTS = $(SOURCES:.c=.o)

TARGETS = q1a q1b q2a q2b q2c q2d a2e q3a q3b q4a

all: $(TARGETS)

q1a: q1/a.o alice.o
	$(CC) -o q1a q1/a.o alice.o $(CFLAGS)

q1b: q1/b.o alice.o
	$(CC) -o q1b q1/b.o alice.o $(CFLAGS)

q2a: q2/a.o alice.o
	$(CC) -o q2a q2/a.o alice.o $(CFLAGS)

q2a: q2/b.o alice.o
	$(CC) -o q2b q2/b.o alice.o $(CFLAGS)

q2a: q2/c.o alice.o
	$(CC) -o q2c q2/c.o alice.o $(CFLAGS)

q2a: q2/d.o alice.o
	$(CC) -o q2d q2/d.o alice.o $(CFLAGS)

q2a: q2/e.o alice.o
	$(CC) -o q2e q2/e.o alice.o $(CFLAGS)

q3a: q3/a.o alice.o
	$(CC) -o q3a q3/a.o alice.o $(CFLAGS)

q3b: q3/b.o bob.o
	$(CC) -o q3b q3/b.o bob.o $(CFLAGS)

q4a: q4/a.o alice.o
	$(CC) -o q4a q4/a.o alice.o $(CFLAGS)

q4b: q4/b.o alice.o
	$(CC) -o q4b q4/b.o alice.o $(CFLAGS)

q1/a.o: q1/a.c
	$(CC) -c q1/a.c -o q1/a.o $(CFLAGS)

q1/b.o: q1/b.c
	$(CC) -c q1/b.c -o q1/b.o $(CFLAGS)

q2/a.o: q2/a.c
	$(CC) -c q2/a.c -o q2/a.o $(CFLAGS)

q2/b.o: q2/b.c
	$(CC) -c q2/b.c -o q2/b.o $(CFLAGS)

q2/c.o: q2/c.c
	$(CC) -c q2/c.c -o q2/c.o $(CFLAGS)

q2/d.o: q2/d.c
	$(CC) -c q2/d.c -o q2/d.o $(CFLAGS)

q2/e.o: q2/e.c
	$(CC) -c q2/e.c -o q2/e.o $(CFLAGS)

q3/a.o: q3/a.c
	$(CC) -c q3/a.c -o q3/a.o $(CFLAGS)

q3/b.o: q3/b.c
	$(CC) -c q3/b.c -o q3/b.o $(CFLAGS)

q4/a.o: q4/a.c
	$(CC) -c q4/a.c -o q4/a.o $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGETS)
