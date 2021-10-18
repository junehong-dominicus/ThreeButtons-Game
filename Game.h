#pragma once
#ifndef _GAME_H
#define _GAME_H

#include<unordered_map>

#include "ConsoleDisplay.h"

#define num_of_buttons 3

class ConsoleDisplay;

enum LED_Colors { LED_OFF, LED_RED, LED_GREEN, LED_ORANGE, LED_ALL } ;
static const char *led_colors_str[] =
        { "Off", "Red", "Green", "Orange" };

class Game {
public:

	Game();

	void play();
  int checkUserGuess(char* user_guess, int* led_colors);
  void printResult(int* led_colors);
	bool userWins();
  void setSequence(char* buttons_sequence);
  char* getSequence();

  ConsoleDisplay* m_console_display;

private:
	void generateRandomSequence();

	char m_buttons_sequence[num_of_buttons] = { '0' };
	char m_user_guess[num_of_buttons];
	bool m_user_wins = false;
	int m_correct_guesses = 0;
	int m_led_colors[num_of_buttons] = { 0 };

  // To do: various number_of_buttons' value support
	std::unordered_map<char, int> m_button_exists = {  // To do: <char, bool>
		{'A', false},
		{'B', false},
		{'C', false}
	};

};

#endif // _GAME_H
