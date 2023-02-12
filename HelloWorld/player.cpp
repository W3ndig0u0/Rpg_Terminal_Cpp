#include <iostream>
#include <string>
#include "creature.cpp"

class Player : public Creature
{

public:
  bool legalAge(int age);
};

// !Set när kontruktorn skapas

bool Player::legalAge(int age)
{
  if (age < 18)
  {
    std::cout << "Du är för ung för att köra, kom tillbaka när du är 18 år." << std::endl;
    return false;
  }

  std::cout << "Ha så kul och lycka till med spelandet" << std::endl;
  return true;
}
