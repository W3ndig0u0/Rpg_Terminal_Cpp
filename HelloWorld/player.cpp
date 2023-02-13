#include <iostream>
#include <string>
#include "creature.cpp"

class Player : public Creature
{

public:
  Player();

  Player(std::string rpgClass, int age, int intelligence, int mp, int maxMp, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Creature(rpgClass, age, intelligence, mp, maxMp, entityName, race, level, experience, hp, maxHp, strength, speed, defence)
  {
    setClass(rpgClass);
    setAge(age);
    setMp(mp);
    setIntelligence(intelligence);
    setEntityName(entityName);
    setRace(race);
    setLevel(level);
    setExperience(experience);
    setHp(hp);
    setMaxMp(maxMp);
    setMaxHp(maxHp);
    setStrength(strength);
    setSpeed(speed);
    setDefence(defence);
  }
};

// !Set när kontruktorn skapas