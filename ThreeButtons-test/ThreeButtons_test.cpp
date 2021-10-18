/**
* Framework-less Unit Tests
*/
#include <iostream>
#include <cstring>
#include <assert.h>

#include "../Game.h"

using namespace std;

// To do: various number_of_buttons' value support

int main() {
  char user_guess[num_of_buttons] = { '0' };
	int correct_guesses = 0;
	int led_colors[num_of_buttons] = { 0 };

  Game *m_game;

  int index = 0;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - Game Class Initializing " << endl;
  cout << "---------------------------------------------------" << endl;

  m_game = new Game();
  string result = m_game->getSequence();
  cout << result << endl;
  assert( (result >= "AAA") && (result <= "CCC") );
  delete m_game;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - LED_GREEN and LED_ORANGE " << endl;
  cout << "---------------------------------------------------" << endl;

  m_game = new Game();
  m_game->setSequence((char*)"ABC");

  memset(user_guess, 'A', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  m_game->printResult(led_colors);
  assert(correct_guesses == 1);
  assert(led_colors[0] == LED_GREEN);
  assert(led_colors[1] == LED_ORANGE);
  assert(led_colors[2] == LED_ORANGE);

  memset(user_guess, 'B', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  m_game->printResult(led_colors);
  assert(correct_guesses == 1);
  assert(led_colors[0] == LED_ORANGE);
  assert(led_colors[1] == LED_GREEN);
  assert(led_colors[2] == LED_ORANGE);

  memset(user_guess, 'C', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  m_game->printResult(led_colors);
  assert(correct_guesses == 1);
  assert(led_colors[0] == LED_ORANGE);
  assert(led_colors[1] == LED_ORANGE);
  assert(led_colors[2] == LED_GREEN);

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - LED_RED " << endl;
  cout << "---------------------------------------------------" << endl;

  m_game->setSequence((char*)"AAA");

  memset(user_guess, 'B', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  m_game->printResult(led_colors);
  assert(correct_guesses == 0);
  assert(led_colors[0] == LED_RED);
  assert(led_colors[1] == LED_RED);
  assert(led_colors[2] == LED_RED);

  memset(user_guess, 'C', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  m_game->printResult(led_colors);
  assert(correct_guesses == 0);
  assert(led_colors[0] == LED_RED);
  assert(led_colors[1] == LED_RED);
  assert(led_colors[2] == LED_RED);

  delete m_game;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - checkUserGuess - 1" << endl;
  cout << "---------------------------------------------------" << endl;

  memset(user_guess, 'A', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    m_game->printResult(led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN) user_guess[i] += 0x01;
      if (user_guess[i] >= 'D') user_guess[i] = 'A';
    }
  }

  assert(correct_guesses == num_of_buttons);
  assert(strncmp(user_guess, m_game->getSequence(), 3) == 0);

  delete m_game;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - checkUserGuess - 2" << endl;
  cout << "---------------------------------------------------" << endl;

  user_guess[0] = 'A';
  user_guess[1] = 'B';
  user_guess[2] = 'C';
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    m_game->printResult(led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN) user_guess[i] += 0x01;
      if (user_guess[i] >= 'D') user_guess[i] = 'A';
    }
  }

  assert(correct_guesses == num_of_buttons);
  assert(strncmp(user_guess, m_game->getSequence(), 3) == 0);

  delete m_game;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - wrong inputs - 1" << endl;
  cout << "---------------------------------------------------" << endl;

  memset(user_guess, 'D', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    m_game->printResult(led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN)
        user_guess[i] += 0x01;
    }
  }

  assert(correct_guesses != num_of_buttons);

  delete m_game;

  cout << "===================================================" << endl;
  cout << index++ << ".Test Case - wrong inputs - 2" << endl;
  cout << "---------------------------------------------------" << endl;

  user_guess[0] = 'A';
  user_guess[1] = 'B';
  user_guess[2] = 'H';
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));

  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    m_game->printResult(led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN)
        user_guess[i] += 0x01;
    }
  }

  assert(correct_guesses != num_of_buttons);

  delete m_game;

  cout << "===================================================" << endl;
  cout << " Passed " << index << " tests!!!" << endl;
  cout << "===================================================" << endl;

  return 0;
}
