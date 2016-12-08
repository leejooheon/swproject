LIB_PATH = ../code
CC = gcc
OUTPUT = output
OBJECT = main.c
CFLAGS = -o

$(OUTPUT): $(OBJECT)
	$(CC) $(OBJECT) -L$(LIB_PATH) -lfuncs \
	$(CFLAGS) $(OUTPUT)

clean:
	rm $(OUTPUT)
