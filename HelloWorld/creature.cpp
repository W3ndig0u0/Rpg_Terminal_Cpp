#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "entity.cpp"

class Creature : public Entity
{
  // !Stats for every entitiy
  std::string class_;
  int age_;
  int mp_;
  int maxMp_;

public:
  std::string classDisplayChoice();
  std::string raceDisplayChoice();
  std::string DisplayChoise(std::vector<std::string> array, std::string choiseWhat);

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
    return "Name: " + getEntityName() + ". Race: " + getRace() + ". Class: " + class_ + ". MaxHp: " + std::to_string(getMaxHp()) + ". Hp: " + std::to_string(getHp()) + ". Level: " + std::to_string(getLevel()) + ". Experience: " + std::to_string(getExperience()) + ". Age: " + std::to_string(age_) + ". MaxMp: " + std::to_string(maxMp_) + ". Mp: " + std::to_string(mp_) + ". Strength: " + std::to_string(getStrength()) + ". Speed: " + std::to_string(getSpeed()) + ". Defence: " + std::to_string(getDefence());
  }
};

std::string Creature::classDisplayChoice()
{
  std::string classes[5] = {"Knight", "Wizard", "Rogue", "Rangers", "Clerics"};
  std::string selectedClasses;
  std::vector<std::string> classVector(classes, classes + 5);
  return DisplayChoise(classVector, selectedClasses);
}

std::string Creature::raceDisplayChoice()
{
  std::string races[5] = {"Human", "Elves", "Dwarfes", "Orc", "Goblin"};
  std::string selectedRace;
  std::vector<std::string> raceVector(races, races + 5);
  return DisplayChoise(raceVector, selectedRace);
}

std::string Creature::DisplayChoise(std::vector<std::string> array, std::string choiseWhat)
{
  bool exists;

  while (!exists)
  {
    std::cout << std::string(20, '\n');
    std::cout << "Choose one of the avaliable Class: " << std::endl;

    for (const std::string &i : array)
    {
      std::cout << i << "\n";
    }

    std::cin >> choiseWhat;

    exists = std::find(array.begin(), array.end(), choiseWhat) != array.end();

    if (exists)
    {
      std::cout << "You choose the Class: " + choiseWhat << std::endl;
      std::cout << "Press any button to continue..." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
      return choiseWhat;
    }

    std::cout << "You did not write an appropiate answer, try again." << std::endl;
    // !Clearar buffern i sin
    std::cin.clear();
    std::cin.sync();
    std::cin.get();
  }

  return "";
}