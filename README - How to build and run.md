### 0. Building and Running Environment

1) MacOS
- GNU Make 3.01
- Apple clang version 13.0.0 (clang-1300.0.29.3)
- boost 1.76.0 for Unit Test Framework Boost.Test
```
$ brew install boost
```

2) Linux - CentOS Stream release 8
- GNU Make 4.2.1
- g++ (GCC) 8.5.0 20210514 (Red Hat 8.5.0-3)
- boost-devel-1.66.0-10.el8.x86_64 for Unit Test Framework Boost.Test
```
$ sudo yum install boost-devel
```

This is a sketch of the Mars-Rover project directory structure:
```
ThreeButtons-Game\ ............. The "ThreeButtons-Game root directory"
  ThreeButtons.cpp
  Game.cpp
  Game.h
  ConsoleDisplay.cpp
  ConsoleDisplay.h
  makefile
  README.md
  README - How to build and run.md
  ThreeButtons-test\
    ThreeButtons_test.cpp
    makefile
  ThreeButtons-test-boost\
    ThreeButtons_test_boost.cpp
    makefile
```

### 1. How to build and run ThreeButtons-Game
Go to the ThreeButtons-Game project root directory and build run:
```
$ cd /path/to/your/ThreeButtons-Game/dir
$ make clean && make
```
And just run:
```
$ ./ThreeButtons
```
### 2. How to build and run ThreeButtons-Game __unit tests__
1) Framework-less Unit Tests
Go to the ThreeButtons-Game project root directory and change director to ThreeButtons-test:
```
$ cd /path/to/your/Mars-Rover/dir
$ cd ThreeButtons-test
```
Build and run:
```
$ make clean && make
$ ./ThreeButtons_test
```
2) Unit Tests using Boost.Test
__Please make sure you already installed boost framework.__
Go to the ThreeButtons-Game project root directory and change director to ThreeButtons-test:
```
$ cd /path/to/your/Mars-Rover/dir
$ cd ThreeButtons-test-boost
```
Build and run:
```
$ make clean && make
$ ./ThreeButtons_test_boost
```
