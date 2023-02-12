#include <iostream>
#include <string>
#include "entity.cpp"

class Creature : public Entity
{
public:
  // !Stats for every entitiy
  std::string entityName;
  std::string race;
  int age;
  int level;
  int experience;
  int hp;
  int mp;
  int strength;
  int speed;
  int defence;
};