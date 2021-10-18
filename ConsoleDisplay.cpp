#include <iostream>
#include "Game.h"
#include "ConsoleDisplay.h"

using namespace std;

void ConsoleDisplay::printNewGameMessage()
{
#ifdef LINUX_VM
	cout << "New game" << endl;
#endif

#ifdef EVM_1_0
	// To do ...
#endif

#ifdef EVM_1_1
	// To do ...
#endif

}

void ConsoleDisplay::promptUserToGuess(char* user_guess)
{
#ifdef LINUX_VM
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
#endif

#ifdef EVM_1_0
	// To do ...
#endif

#ifdef EVM_1_1
	// To do ...
#endif
}

#ifdef LINUX_VM
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
#ifdef LINUX_VM
	for (int i = 0; i < num_of_buttons; i++) {
		cout << "LED" << i+1 << ":" << led_colors_str[led_colors[i]] << " ";
	}
	cout << endl;
#endif

#ifdef EVM_1_0
	// To do ...
#endif

#ifdef EVM_1_1
	// To do ...
#endif
}

void ConsoleDisplay::printWinMessage()
{
#ifdef LINUX_VM
	cout << "YOU WIN!!! " << endl;
#endif

#ifdef EVM_1_0
	// To do ...
#endif

#ifdef EVM_1_1
	// To do ...
#endif
}
