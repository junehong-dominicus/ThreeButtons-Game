### How to migrate to new target hardware

* ThreeButtons-Game Software Architecture

|   Module                | Description                         |
|:------------------------|:-----------------------------------:|
|   ThreeButtons.cpp      |  Main Loop                          |
|   Game.cpp              |  Game Engine Core                   |
|   ConsoleDisplay.cpp    |  Hardware Abstraction Layer (HAL)   |

1) Define target hardware name and set compile option in __makefile__.
```
# For Linux Console
# COMPILE_OPTS = -DLINUX_VM
# For EVM Board version 1.0
# COMPILE_OPTS = -DEVM_1_0		# <=== Set target hardware here. ex) EVM_1_0
# For EVM Board version 1.1
# COMPILE_OPTS = -DEVM_1_1
```

2) Implement target hardware functions in __ConsoleDisplay.cpp__ file.
```
#ifdef LINUX_VM
	cout << "New game" << endl;
#endif

#ifdef EVM_1_0
	// To do ...					# <=== Implement target hardware function here.
#endif

#ifdef EVM_1_1
	// To do ...
#endif
```

* To do: __Adapter Pattern__

* To do: Cross-Compile makefile

```
#Set Architecture
ARCH := arm

#Compilers
ifeq ($(ARCH),arm)
CC := /usr/local/arm/bin/arm-unknown-linux-gnueabi-g++
GCC := /usr/local/arm/bin/arm-unknown-linux-gnueabi-gcc
else
CC := g++
GCC := gcc
endif
```

```
make ARCH=x86              // Build Release version X86
```
