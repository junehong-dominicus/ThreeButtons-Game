/**
* Unit Test Framework - Boost.Test
* https://www.boost.org/doc/libs/1_69_0/more/getting_started/unix-variants.html#easy-build-and-install
*
* MacOSX:
* $ brew install boost
* CentoOS:
* $ sudo yum install boost-devel
*
* How to build
* MacOS:
* > g++ -std=c++11 -I /usr/local/opt/boost/include -L/usr/local/Cellar/boost/1.76.0/lib ThreeButtons_test-boost.cpp -o ThreeButtons_test-boost -lboost_unit_test_framework
* Linux
* > g++ -std=c++11 -lboost_unit_test_framework
*/
#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>

// Nullary method of a class bound to shared class instance and manually registered.
using namespace boost::unit_test;

class test_class
{
public:
  // void test_method1()
  // {
  //   BOOST_TEST( true /* test assertion */ );
  // }
  // void test_method2()
  // {
  //   BOOST_TEST( false /* test assertion */ );
  // }
  // void test_method3()
  // {
  //   BOOST_TEST( true /* test assertion */ );
  // }
};

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
  // boost::shared_ptr<test_class> tester( new test_class );
  //
  // framework::master_test_suite().
  //   add( BOOST_TEST_CASE( boost::bind( &test_class::test_method1, tester )));
  // framework::master_test_suite().
  //   add( BOOST_TEST_CASE( boost::bind( &test_class::test_method2, tester )));
  //   framework::master_test_suite().
  //     add( BOOST_TEST_CASE( boost::bind( &test_class::test_method3, tester )));
  return 0;
}

#define BOOST_TEST_MODULE ThreeButtonsGameTest
#include <boost/test/unit_test.hpp>

#include "../Game.h"

using namespace std;

// To do: various number_of_buttons' value support

BOOST_AUTO_TEST_CASE( GameClass_test )
{
  Game *m_game;
  m_game = new Game();
  string result = m_game->getSequence();
  BOOST_CHECK((result >= "AAA") && (result <= "CCC"));
  delete m_game;
}

BOOST_AUTO_TEST_CASE( LED_test )
{
  char user_guess[num_of_buttons] = { '0' };
	int correct_guesses = 0;
	int led_colors[num_of_buttons] = { 0 };

  Game *m_game;

  m_game = new Game();
  m_game->setSequence((char*)"ABC");

  memset(user_guess, 'A', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  BOOST_CHECK(correct_guesses == 1);
  BOOST_CHECK(led_colors[0] == LED_GREEN);
  BOOST_CHECK(led_colors[1] == LED_ORANGE);
  BOOST_CHECK(led_colors[2] == LED_ORANGE);

  memset(user_guess, 'B', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  BOOST_CHECK(correct_guesses == 1);
  BOOST_CHECK(led_colors[0] == LED_ORANGE);
  BOOST_CHECK(led_colors[1] == LED_GREEN);
  BOOST_CHECK(led_colors[2] == LED_ORANGE);

  memset(user_guess, 'C', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  BOOST_CHECK(correct_guesses == 1);
  BOOST_CHECK(led_colors[0] == LED_ORANGE);
  BOOST_CHECK(led_colors[1] == LED_ORANGE);
  BOOST_CHECK(led_colors[2] == LED_GREEN);

  m_game->setSequence((char*)"AAA");
  memset(user_guess, 'B', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  BOOST_CHECK(correct_guesses == 0);
  BOOST_CHECK(led_colors[0] == LED_RED);
  BOOST_CHECK(led_colors[1] == LED_RED);
  BOOST_CHECK(led_colors[2] == LED_RED);

  memset(user_guess, 'C', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
  BOOST_CHECK(correct_guesses == 0);
  BOOST_CHECK(led_colors[0] == LED_RED);
  BOOST_CHECK(led_colors[1] == LED_RED);
  BOOST_CHECK(led_colors[2] == LED_RED);

  delete m_game;
}

BOOST_AUTO_TEST_CASE( checkUserGuess_test )
{
  char user_guess[num_of_buttons] = { '0' };
	int correct_guesses = 0;
	int led_colors[num_of_buttons] = { 0 };

  Game *m_game;

  memset(user_guess, 'A', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN) user_guess[i] += 0x01;
      if (user_guess[i] >= 'D') user_guess[i] = 'A';
    }
  }
  BOOST_CHECK(correct_guesses == num_of_buttons);
  BOOST_CHECK(strncmp(user_guess, m_game->getSequence(), 3) == 0);
  delete m_game;

  user_guess[0] = 'A';
  user_guess[1] = 'B';
  user_guess[2] = 'C';
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN) user_guess[i] += 0x01;
      if (user_guess[i] >= 'D') user_guess[i] = 'A';
    }
  }
  BOOST_CHECK(correct_guesses == num_of_buttons);
  BOOST_CHECK(strncmp(user_guess, m_game->getSequence(), 3) == 0);
  delete m_game;
}

BOOST_AUTO_TEST_CASE( checkUserGuess_wrong_input_test )
{
  char user_guess[num_of_buttons] = { '0' };
	int correct_guesses = 0;
	int led_colors[num_of_buttons] = { 0 };

  Game *m_game;

  memset(user_guess, 'D', num_of_buttons*sizeof(char));
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN)
        user_guess[i] += 0x01;
    }
  }
  BOOST_CHECK(correct_guesses != num_of_buttons);
  delete m_game;

  user_guess[0] = 'A';
  user_guess[1] = 'B';
  user_guess[2] = 'H';
  memset(led_colors, LED_OFF, num_of_buttons*sizeof(int));
  m_game = new Game();
  for (int j = 0; j < num_of_buttons; j++) {
    correct_guesses = m_game->checkUserGuess(user_guess, led_colors);
    for (int i = 0; i < num_of_buttons; i++) {
      if (led_colors[i] != LED_GREEN)
        user_guess[i] += 0x01;
    }
  }
  BOOST_CHECK(correct_guesses != num_of_buttons);
  delete m_game;
}
