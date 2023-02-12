#include <iostream>
#include <string>
#include "creature.cpp"

class Player : public Creature
{
  std::string name;
  int years;
  int score;

public:
  // !Deklarerar Konstruktorn och funktioner innanför klassen
  Player(const std::string name, int years, int score);
  void addScore(int score);
  bool legalAge(int years);
  void setAge(int age);
  void setName(std::string name);

  // !Gör en string som innehåller variablerna
  std::string toString() { return "Name: " + name + " Years: " + std::to_string(years) + " Score: " + std::to_string(score); }

  // !Getters
  std::string getName() { return name; }
  int getYears() { return years; }
  int getScore() { return score; }
};

// !Set när kontruktorn skapas
Player::Player(const std::string name, int years, int score)
    : name(name),
      years(years),
      score(score)
{
}

void Player::setAge(int age)
{
  years = age;
}

void Player::setName(std::string actualName)
{
  name = actualName;
}

void Player::addScore(int score)
{
  score++;
}

bool Player::legalAge(int years)
{
  if (years < 18)
  {
    std::cout << "Du är för ung för att köra, kom tillbaka när du är 18 år." << std::endl;
    return false;
  }

  std::cout << "Ha så kul och lycka till med spelandet" << std::endl;
  return true;
}
