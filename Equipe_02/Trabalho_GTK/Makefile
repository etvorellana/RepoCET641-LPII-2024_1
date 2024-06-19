CC := gcc
OUTPUT := out.com
SRC := $(wildcard src/*.c)

INCFLAGS := $(shell pkg-config --cflags gtk+-3.0)
LIBFLAGS := $(shell pkg-config --libs gtk+-3.0)
CFLAGS := $(INCFLAGS) $(LIBFLAGS) -Wall -std=c99 -pedantic

run: $(OUTPUT)
	./$(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) -o $@ $(SRC) $(CFLAGS)

.PHONY: run
