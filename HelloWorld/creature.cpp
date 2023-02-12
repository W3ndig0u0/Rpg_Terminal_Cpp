#include <iostream>
#include <string>
#include "entity.cpp"

class Creature : public Entity
{
  // !Stats for every entitiy
  std::string class_;
  int age_;
  int mp_;
  int maxMp_;

public:
  void classDisplayChoice();
  void raceDisplayChoice();

  std::string getClass() { return class_; }
  void setClass(std::string rpgClass)
  {
    class_ = rpgClass;
  }

  int getAge() { return age_; }
  void setAge(int age)
  {
    age_ = age;
  }

  int getMp() { return mp_; }
  void setMp(int mp)
  {
    mp_ = mp;
  }

  int getMaxMp() { return maxMp_; }
  void setMaxMp(int maxMp)
  {
    maxMp_ = maxMp;
  }

  // ?Inventory...
  // Inventory inventory;

  Creature(std::string rpgClass, int age, int mp, int maxMp, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Entity(entityName, race, level, experience, hp, maxHp, strength, speed, defence)
  {
    class_ = rpgClass;
    age_ = age;
    mp_ = mp;
    maxMp_ = maxMp;
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
    return "Name: " + getEntityName() + ". Race: " + getRace() + ". MaxHp: " + std::to_string(getMaxHp()) + ". Hp: " + std::to_string(getHp()) + ". Level: " + std::to_string(getLevel()) + ". Experience: " + std::to_string(getExperience()) + ". Age: " + std::to_string(age_) + ". MaxMp: " + std::to_string(maxMp_) + ". Mp: " + std::to_string(mp_) + ". Strength: " + std::to_string(getStrength()) + ". Speed: " + std::to_string(getSpeed()) + ". Defence: " + std::to_string(getDefence());
  }
};

void Creature::classDisplayChoice()
{
  std::string classes[5] = {"Knight", "Wizard", "Rogue", "Rangers", "Clerics"};
  for (std::string i : classes)
  {
    std::cout << i << "\n";
  }
}

void Creature::raceDisplayChoice()
{
  std::string selectedRace;

  std::string races[5] = {"Human", "Elves", "Dwarfes", "Orc", "Goblin"};
  for (std::string i : races)
  {
    std::cout << i << "\n";
  }

  std::cin >> selectedRace;
}