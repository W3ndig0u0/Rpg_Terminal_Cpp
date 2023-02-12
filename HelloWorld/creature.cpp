#include <iostream>
#include <string>
#include "entity.cpp"

class Creature : public Entity
{
  // !Stats for every entitiy
  int age_;
  int mp_;
  int maxMp_;

public:
  int getAge() { return age_; }
  void setAge(int Realage)
  {
    age_ = Realage;
  }

  int getMp() { return mp_; }
  void setMp(int realMp)
  {
    mp_ = realMp;
  }

  int getMaxMp() { return maxMp_; }
  void setMaxMp(int realMaxMp)
  {
    maxMp_ = realMaxMp;
  }

  // ?Inventory...
  // Inventory inventory;

  Creature(int age, int mp, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Entity(entityName, race, level, experience, hp, maxHp, strength, speed, defence)
  {
    age_ = age;
    mp_ = mp;
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

  std::string toString()
  {
    return "Name: " + getEntityName() + ". Race: " + getRace();
    +". maxHp: " + std::to_string(getMaxHp());
    +". Hp: " + std::to_string(getHp());
    +". Level: " + std::to_string(getLevel());
    +". Experience: " + std::to_string(getExperience());
    +". Age: " + age_;
    +". MaxMp: " + maxMp_;
    +". Mp: " + mp_;
    +". Strength: " + std::to_string(getStrength());
    +". Speed: " + std::to_string(getSpeed());
    +". Defence: " + std::to_string(getDefence());
  }
};