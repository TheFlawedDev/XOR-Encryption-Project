# Author Jorge Velaquez
# Date 02/13/2026

CC = g++
WFLAG = -Wall #Compiler Flags
INC = ./include/
SRC = ./src/

XOR.o : $(SRC)XOR.cpp $(INC)XOR.h
	$(CC) $(WFLAG) -c $(SRC)XOR.cpp -I$(INC)

main.o : main.cpp
	$(CC) $(WFLAG) -c main.cpp -I$(INC)

mainTest : XOR.o main.o
	$(CC) $(WFLAG) -o mainTest XOR.o main.o

clean :
	rm -f mainTest *.o 
