
PROJ_NAME=polinomio

C_SOURCE=$(wildcard *.c)

H_SOURCE=$(wildcard *.h)

OBJ=$(C_SOURCE:.c=.o)

CC=gcc

CC_FLAGS=-c -ansi -Wall -pedantic


all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ -lm

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS) -lm

main.o: main.c $(H.SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS) -lm

clean:
	rm -rf *.o *~ polinomio