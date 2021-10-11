# ThreeButtons-Game
## Test Plan and Results
### 1. Framework-less Unit Tests using macro assert

#### 0) How to build and run ThreeButtons-Game framework-less unit tests
1. Go to the ThreeButtons-Game project root directory and change director to ThreeButtons-test:
```
$ cd /path/to/your/ThreeButtons-Game/dir
$ cd ThreeButtons-test
```
2. Build and run:
```
$ make clean && make
$ ./ThreeButtons_test
```

#### 1) Test Plan and Cases
1. Game Class Initializing Test<br>
; Create a instance of Game() class and check the generated sequence values.
* Input : new Game();
* Expected output: "AAA" >= and <= "CCC"

2. LED_GREEN and LED_ORANGE Test<br>
; Check returned color values for green and orange LED
- Set generated sequence as "ABC"
* Input : user_guess = "AAA"
* Expected output: LED_GREEN, LED_ORANGE, LED_ORANGE
* Input : user_guess = "BBB"
* Expected output: LED_ORANGE, LED_GREEN, LED_ORANGE
* Input : user_guess = "AAA"
* Expected output: LED_GREEN, LED_ORANGE, LED_ORANGE
* Input : user_guess = "CCC"
* Expected output: LED_ORANGE, LED_ORANGE, LED_GREEN

3. LED_RED Test<br>
; Check returned color values for red LED
- Set generated sequence as "AAA"
* Input : user_guess = "BBB"
* Expected output: LED_RED, LED_RED, LED_RED
* Input : user_guess = "CCC"
* Expected output: LED_RED, LED_RED, LED_RED

4. checkUserGuess Test-1<br>
; Check checkUserGuess() operation
- Generate random sequence
* Input : user_guess = "AAA" and change value of guess with LED_RED or LED_GREEN, running the the loop 3 times.
* Expected output: correct_guesses == num_of_buttons, user_guess == random generated sequence

5. checkUserGuess Test-2<br>
; Check checkUserGuess() operation one more time with different input
- Generate random sequence
* Input : user_guess = "ABC" and change value of guess with LED_RED or LED_GREEN, running the the loop 3 times.
* Expected output: correct_guesses == num_of_buttons, user_guess == random generated sequence

6. Wrong input Test-1<br>
; Check checkUserGuess() handles wrong inputs properly
- Generate random sequence
* Input : user_guess = "DDD" and increase value of guess by 0x01, running the the loop 3 times.
* Expected output: correct_guesses != num_of_buttons

7. Wrong input Test-2<br>
; Check checkUserGuess() handles wrong inputs properly
- Generate random sequence
* Input : user_guess = "ABH" and increase value of guess by 0x01, running the the loop 3 times.
* Expected output: correct_guesses != num_of_buttons

- Check "Passed" message with test case number.

#### 2) Test results
```

```

### 2. Framework Unit Tests using Boost.Test

#### 0) How to build and run ThreeButtons-Game unit tests with Boost.Test framework
__Please make sure you already installed boost framework.__
* MacOS
```
$ brew install boost
```
* Linux - CentOS Stream release 8
```
$ sudo yum install boost-devel
```
Go to the ThreeButtons-Game project root directory and change director to ThreeButtons-test:
```
$ cd /path/to/your/ThreeButtons-Game/dir
$ cd ThreeButtons-test-boost
```
Build and run:
```
$ make clean && make
$ ./ThreeButtons_test_boost
```

#### 1) Test Plan and Cases
1. GameClass_test: Game Class Initializing Test<br>
; Create a instance of Game() class and check the generated sequence values.
* Input : new Game();
* Expected output: "AAA" >= and <= "CCC"

2. LED_test: LED_GREEN and LED_ORANGE Test<br>
; Check returned color values for green and orange LED
- Set generated sequence as "ABC"
* Input : user_guess = "AAA"
* Expected output: LED_GREEN, LED_ORANGE, LED_ORANGE
* Input : user_guess = "BBB"
* Expected output: LED_ORANGE, LED_GREEN, LED_ORANGE
* Input : user_guess = "AAA"
* Expected output: LED_GREEN, LED_ORANGE, LED_ORANGE
* Input : user_guess = "CCC"
* Expected output: LED_ORANGE, LED_ORANGE, LED_GREEN

3. LED_test: LED_RED Test<br>
; Check returned color values for red LED
- Set generated sequence as "AAA"
* Input : user_guess = "BBB"
* Expected output: LED_RED, LED_RED, LED_RED
* Input : user_guess = "CCC"
* Expected output: LED_RED, LED_RED, LED_RED

4. checkUserGuess_test: checkUserGuess Test-1<br>
; Check checkUserGuess() operation
- Generate random sequence
* Input : user_guess = "AAA" and change value of guess with LED_RED or LED_GREEN, running the the loop 3 times.
* Expected output: correct_guesses == num_of_buttons, user_guess == random generated sequence

5. checkUserGuess_test: checkUserGuess Test-2<br>
; Check checkUserGuess() operation one more time with different input
- Generate random sequence
* Input : user_guess = "ABC" and change value of guess with LED_RED or LED_GREEN, running the the loop 3 times.
* Expected output: correct_guesses == num_of_buttons, user_guess == random generated sequence

6. checkUserGuess_wrong_input_test: Wrong input Test-1<br>
; Check checkUserGuess() handles wrong inputs properly
- Generate random sequence
* Input : user_guess = "DDD" and increase value of guess by 0x01, running the the loop 3 times.
* Expected output: correct_guesses != num_of_buttons

7. checkUserGuess_wrong_input_test: Wrong input Test-2<br>
; Check checkUserGuess() handles wrong inputs properly
- Generate random sequence
* Input : user_guess = "ABH" and increase value of guess by 0x01, running the the loop 3 times.
* Expected output: correct_guesses != num_of_buttons

8. Check .


#### 2) Test results