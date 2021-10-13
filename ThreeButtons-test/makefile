# *****************************************************
# Variables to control Makefile operation

PROG = ThreeButtons_test
CC = g++
CFLAGS = -Wall -g -std=c++11
# For Linux Console
COMPILE_OPTS = -DLINUX_VM
# For EVM Board version 1.0
# COMPILE_OPTS = -DEVM_1_0
# For EVM Board version 1.1
# COMPILE_OPTS = -DEVM_1_1
LDFLAGS =
OBJS = ThreeButtons_test.o Game.o ConsoleDisplay.o

# ****************************************************

$(PROG) : $(OBJS)
		$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

ThreeButtons_test.o :
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ThreeButtons_test.cpp

Game.o : ../Game.h
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ../Game.cpp

ConsoleDisplay.o : ../ConsoleDisplay.h
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ../ConsoleDisplay.cpp

.PHONY : clean
clean :
		rm -f $(PROG) $(OBJS)
