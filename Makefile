CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I.

SOURCES = data_structures/graph/graph.c data_structures/hash_table_chain/ht_chaining.c test.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = .\build\test.exe

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	del /s algorithms\*.o $(TARGET)

.PHONY: all clean