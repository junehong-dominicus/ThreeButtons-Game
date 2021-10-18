#include <iostream>

#include "Game.h"

int main() {
  Game *m_game;

  while (1) {
    m_game = new Game();
    m_game->printNewGameMessage();
    do {
      m_game->play();
    } while(!m_game->userWins());
    delete m_game;
  }

  return 0;
}
