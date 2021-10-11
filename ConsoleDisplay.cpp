#include <iostream>
#include "ConsoleDisplay.h"
#include "Game.h"

using namespace std;

void ConsoleDisplay::printNewGameMessage()
{
#if (TARGET_HW == LINUX_VM)
	cout << "New game" << endl;
#elif (TARGET_HW == EVM_1_0)
	// To do ...
#elif (TARGET_HW == EVM_1_1)
	// To do ...
#else
	#error No target selected
#endif
}

void ConsoleDisplay::promptUserToGuess(char* user_guess)
{
#if (TARGET_HW == LINUX_VM)
	cout << "Take a guess: ";
	for (int i = 0; i < num_of_buttons; i++) {
		do {
			cin >> user_guess[i];
		} while (!inputCorrect(toupper(user_guess[i])));
	}
	// Make all letters uppercase
	for (int i = 0; i < num_of_buttons; i++) {
		user_guess[i] = toupper(user_guess[i]);
	}
#elif (TARGET_HW == EVM_1_0)
	// To do ...
#elif (TARGET_HW == EVM_1_1)
	// To do ...
#else
	#error No target selected
#endif
}

#if (TARGET_HW == LINUX_VM)
bool ConsoleDisplay::inputCorrect(char guess)
{
	bool retval = false;

	if (guess == 'A' || guess == 'B' || guess == 'C') {
		retval = true;
	}
	else {
		cout << "Incorrect input! You have to pick one of three following letters:";
		cout << " A, B, C " << endl;
	}

	return retval;
}
#endif

void ConsoleDisplay::printResult(int* led_colors)
{
#if (TARGET_HW == LINUX_VM)
	for (int i = 0; i < num_of_buttons; i++) {
		cout << "LED" << i+1 << ":" << led_colors_str[led_colors[i]] << " ";
	}
	cout << endl;
#elif (TARGET_HW == EVM_1_0)
	// To do ...
#elif (TARGET_HW == EVM_1_1)
	// To do ...
#else	// Linux console
	#error No target selected
#endif
}

void ConsoleDisplay::printWinMessage()
{
#if (TARGET_HW == LINUX_VM)
	cout << "YOU WIN!!! " << endl;
#elif (TARGET_HW == EVM_1_0)
	// To do ...
#elif (TARGET_HW == EVM_1_1)
	// To do ...
#else	// Linux console
	#error No target selected
#endif
}
