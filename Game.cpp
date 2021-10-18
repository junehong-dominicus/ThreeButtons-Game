#include <ctime>
#include <iostream>
#include <cstring>

#include "Game.h"
#include "ConsoleDisplay.h"

Game::Game()
{
	memset(m_led_colors, LED_OFF, num_of_buttons*sizeof(int));
	generateRandomSequence();
}

void Game::play()
{
	m_console_display->promptUserToGuess(m_user_guess);

	m_correct_guesses = checkUserGuess(m_user_guess, m_led_colors);

	m_console_display->printResult(m_led_colors);

	if (m_correct_guesses == num_of_buttons) {
		m_user_wins = true;
		m_console_display->printWinMessage();
	}
}

int Game::checkUserGuess(char* user_guess, int* led_colors)
{
	int correct_guesses = 0;

	for (int i = 0; i < num_of_buttons; i++) {
		if (user_guess[i] == m_buttons_sequence[i]) {
			correct_guesses++;
			led_colors[i] = LED_GREEN; //green
		}
		else {
			if (m_button_exists[user_guess[i]]) {
				led_colors[i] = LED_ORANGE; // orange
			}
			else {
				led_colors[i] = LED_RED;// red
			}
		}
	}
	return correct_guesses;
}

void Game::printResult(int* led_colors)
{
	m_console_display->printResult(led_colors);
}

bool Game::userWins()
{
	return m_user_wins;
}

void Game::generateRandomSequence()
{
	srand(time(0));

	for (int i = 0; i < num_of_buttons; i++) {
		m_buttons_sequence[i] = 'A' + rand() % num_of_buttons;
		// set the exist flag for generated letter to true
		m_button_exists[m_buttons_sequence[i]] = true;
	}
}

// For test
void Game::setSequence(char* buttons_sequence)
{
	// To do: various number_of_buttons' value support
	m_button_exists['A'] = false;
	m_button_exists['B'] = false;
	m_button_exists['C'] = false;

	for (int i = 0; i < num_of_buttons; i++) {
		m_buttons_sequence[i] = buttons_sequence[i];
		m_button_exists[m_buttons_sequence[i]] = true;
	}
}

char* Game::getSequence()
{
	return m_buttons_sequence;
}
