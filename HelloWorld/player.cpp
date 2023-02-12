#include <iostream>
#include <string>
#include "creature.cpp"

class Player : public Creature
{

public:
  Player();

  Player(int age, int mp, int maxMp, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Creature(age, mp, maxMp, entityName, race, level, experience, hp, maxHp, strength, speed, defence)
  {
    setAge(age);
    setMp(mp);
    setMaxMp(maxMp);
    setEntityName(entityName);
    setRace(race);
    setLevel(level);
    setExperience(experience);
    setHp(hp);
    setMaxHp(maxHp);
    setStrength(strength);
    setSpeed(speed);
    setDefence(defence);
  }
};

// !Set när kontruktorn skapas