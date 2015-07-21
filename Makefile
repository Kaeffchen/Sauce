CC = gcc
CFLAGS = -std=c99 -Wall -Werror
#Uncomment the following line to compile with debug information
DEBUG = -g
OBJECTS = four-in-a-row.o graphic.o getch.o
EXEC = fiar

all: fiar

fiar: $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $(DEBUG) $<
