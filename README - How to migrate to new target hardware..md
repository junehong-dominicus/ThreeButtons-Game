### How to migrate to new target hardware

* ThreeButtons-Game Software Architecture

   ThreeButtons.cpp     |  Main Loop
------------------------|-----------------------------------
   Game.cpp             |  Game Engine Core
------------------------|-----------------------------------
   ConsoleDisplay.cpp   |  Hardware Abstraction Layer (HAL)

1) Define target hardware name and set compile option in __makefile__.
```
PROG = ThreeButtons
CC = g++
CFLAGS = -Wall -g -std=c++11
# For Linux Console
#COMPILE_OPTS = -DTARGET_HW=LINUX_VM
# For EVM Board version 1.0   
COMPILE_OPTS = -DTARGET_HW=EVM_1_0  # <=== Set compile option here. ex) EVM_1_0
# For EVM Board version 1.1
# COMPILE_OPTS = -DTARGET_HW=EVM_1_1
LDFLAGS =
OBJS = ThreeButtons.o Game.o ConsoleDisplay.o
```

2) Implement target hardware functions in __ConsoleDisplay.cpp__ file.
```
#if (TARGET_HW == LINUX_VM)
	cout << "New game" << endl;
#elif (TARGET_HW == EVM_1_0)
	// To do ...                 # <=== Implement target hardware function here.
#elif (TARGET_HW == EVM_1_1)
	// To do ...
#else
	#error No target selected
#endif
```
