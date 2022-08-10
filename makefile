OBJECTS = readLib.c main.c
FLAGS = -Wall
all: ${OBJECTS} readLib.h
	gcc ${FLAGS} ${OBJECTS} -o mysort

purge: mysort
	rm mysort