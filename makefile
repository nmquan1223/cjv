CC = gcc
CFLAGS = -std=c11 -O0 -g -Wall -Wextra -Wpedantic -Iinclude
SOURCES = $(wildcard src/*.c)
all: cjv
cjv: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o cjv
clean:
	rm -f cjv cjv.exe