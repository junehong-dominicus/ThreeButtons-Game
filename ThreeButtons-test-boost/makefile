# *****************************************************
# Variables to control Makefile operation

PROG = ThreeButtons_test_boost
CC = g++
CFLAGS = -Wall -g -std=c++11
# For Linux Console
COMPILE_OPTS = -DTARGET_HW=LINUX_VM
# For EVM Board version 1.0
# COMPILE_OPTS = -DTARGET_HW=EVM_1_0
# For EVM Board version 1.1
# COMPILE_OPTS = -DTARGET_HW=EVM_1_1

# for MacOSX
LDFLAGS = -I /usr/local/opt/boost/include -L/usr/local/Cellar/boost/1.76.0/lib -lboost_unit_test_framework
# for Linux
# LDFLAGS =

OBJS = ThreeButtons_test_boost.o Game.o ConsoleDisplay.o

# ****************************************************

$(PROG) : $(OBJS)
		$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

ThreeButtons_test-boost.o :
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ThreeButtons_test_boost.cpp

Game.o : ../Game.h
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ../Game.cpp

ConsoleDisplay.o : ../ConsoleDisplay.h
		$(CC) $(CFLAGS) $(COMPILE_OPTS) -c ../ConsoleDisplay.cpp

.PHONY : clean
clean :
		rm -f $(PROG) $(OBJS)
