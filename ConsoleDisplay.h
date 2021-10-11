#ifndef _CONSOLEDISPLAY_H
#define _CONSOLEDISPLAY_H
#pragma once

#include <string>

class Game;

class ConsoleDisplay {
public:
	void printNewGameMessage();
	void promptUserToGuess(char* user_guess);
	void printWrongInputMessage();
	void printWinMessage();
	void printResult(int* led_colors);

private:
	bool inputCorrect(char guess);

};

#endif // _CONSOLEDISPLAY_H
