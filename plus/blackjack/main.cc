#include <iostream>
#include <string>
#include <ctime>

#include "IsaacRand.hh"

int randint (int start, int end, IsaacRand* rng) {
  int range = end - start;
  return rng->getNext() % range + start;
}

int deal (IsaacRand* rng) {
  int hand = randint(1, 11, rng) + randint(1, 11, rng);
  while (hand < 16) {
    hand += randint(1, 11, rng);
  }
  return hand;
}

int getHand (IsaacRand* rng) {
  int hand = randint(1, 11, rng) + randint(1, 11, rng);

  std::cout <<  "Your hand is: " << hand << ".";
  while (hand < 21) {
    std::string input;
    std::cout << " What do you do? ";
    std::cin >> input;

    if (input == "hit" || input == "HIT" || input == "Hit" ||
        input == "h" || input == "H") {
      hand += randint(1, 11, rng);
    } else if (input == "stand" || input == "STAND" || input == "Stand" ||
        input == "s" || input == "S") {
      break;
    } else {
      std::cout << "Invalid input!" << std::endl;
    }

    std::cout <<  "Your hand is: " << hand << ".";
  }

  std::cout << std::endl;

  return hand;
}

void gameLoop (IsaacRand* rng) {

  int money = randint(200, 500, rng);
  std::cout << "You have $" << money << std::endl;

  for (;;) {
    
    int bet;
    std::cout << "How much would you like to bet? ";
    std::cin >> bet;

    int dealer = deal(rng);
    int player = getHand(rng);

    std::cout << "Dealer had: " << dealer << ". ";
    std::cout << "You had: " << player << ". " << std::endl;

    if (player > 21) {
      // player loses!
      std::cout << "You lose!" << std::endl;
      money -= bet;
    } else if (dealer > 21) {
      // player wins!
      std::cout << "You win!" << std::endl;
      money += bet;
    } else if (dealer >= player) {
      // player loses!
      std::cout << "You lose!" << std::endl;
      money -= bet;
    } else {
      // player wins!
      std::cout << "You win!" << std::endl;
      money += bet;
    }

    std::cout << "You have $" << money << std::endl;

    std::string input;
    std::cout << "Play another hand? ";
    std::cin >> input;
    if (input == "no" || input == "NO" || input == "n" || input == "N") {
      break;
    }
  }
}

void main () {
  IsaacRand rng(std::time(0));

  gameLoop(&rng);
}
