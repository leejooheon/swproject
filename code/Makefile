CC = gcc
CFLAGS = -c
OBJFILES = getFoodFunction.o saveFoodDB.o user.o userInfo.o userInput.o 
HEADER_PATH = ../header/
OUTPUT = libfuncs.a

$(OUTPUT): $(OBJFILES)
	ar rv $(OUTPUT) $^

%.o: %.c
	$(CC) $(CFLAGS) $< -I$(HEADER_PATH)

clean:
	rm *.o $(OUTPUT)
