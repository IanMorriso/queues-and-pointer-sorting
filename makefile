CC = gcc
CFLAGS = -Wall -std=c99 -ggdb

ex10q1: ex10q1.o lab10a.o
	$(CC) $(CFLAGS) $^ -o $@

ex10q1.o: ex10q1.c lab10a.h

ex10q2: ex10q2.o lab10b.o
	$(CC) $(CFLAGS) $^ -o $@

ex10q2.o: ex10q2.c lab10b.h
