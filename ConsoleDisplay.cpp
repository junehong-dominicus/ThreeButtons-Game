#include <iostream>
#include "ConsoleDisplay.h"
#include "Game.h"

using namespace std;

void ConsoleDisplay::printNewGameMessage()
{
// #if (TARGET_HW == LINUX_VM)
#ifdef LINUX_VM
	cout << "New game" << endl;
#endif

#ifdef EVM_1_0
	// To do ...
	cout << "HW10 - New game" << endl;
#endif

#ifdef EVM_1_1
	// To do ...
	cout << "HW11 - New game" << endl;
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
	cout << "HW10 - Take a guess: ";
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

#ifdef EVM_1_1
	// To do ...
	cout << "HW11 - Take a guess: ";
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
}

#ifdef LINUX_VM
// #ifdef EVM_1_0
// #ifdef EVM_1_1
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
	for (int i = 0; i < num_of_buttons; i++) {
		cout << "HW10 - LED" << i+1 << ":" << led_colors_str[led_colors[i]] << " ";
	}
	cout << endl;
#endif

#ifdef EVM_1_1
	// To do ...
	for (int i = 0; i < num_of_buttons; i++) {
		cout << "HW11 - LED" << i+1 << ":" << led_colors_str[led_colors[i]] << " ";
	}
	cout << endl;
#endif
}

void ConsoleDisplay::printWinMessage()
{
#ifdef LINUX_VM
	cout << "YOU WIN!!! " << endl;
#endif

#ifdef EVM_1_0
	// To do ...
	cout << "HW10 - YOU WIN!!! " << endl;
#endif

#ifdef EVM_1_1
	// To do ...
	cout << "HW11 - YOU WIN!!! " << endl;
#endif
}
