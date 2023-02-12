#include <iostream>
#include <string>
#include "entity.cpp"

class Item : public Entity
{
public:
  // !Stats for every entitiy
  std::string entityName;
  std::string race;
  int level;
  int experience;
  int hp;
  int strength;
  int speed;
  int defence;
};