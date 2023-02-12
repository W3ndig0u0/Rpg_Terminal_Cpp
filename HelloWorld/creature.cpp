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
  std::string DisplayChoise(std::vector<std::string> arrayChoose, std::string choiseWhat, std::string input, std::vector<std::string> arrayExplainChoise);

  std::string getClass()
  {
    return class_;
  }
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
  std::string classesExplain[5] = {
      "+[Uncommon] Sword, +[Common]Armor, +2x [Common] Hp Potions ",
      "+[Uncommon] Magic Wand, +[Common] Robe, +2x [Common] Mp Potions ",
      "+[Uncommon] Dagger, +[Common] Lesser Bow, +[Common] Thief Hood, +2x [Common] Arrows ",
      "+[Uncommon] Long Bow, +[Common] Cloak, +10x [Common] Arrows + 1x [Common] Hp Potions, +1x [Common] Mp Potions",
      "+[Uncommon] Handbook, +[Common] Small Mace, +[Common] Robe, +2x [Common] Mp Potions"};
  std::string selectedClasses;

  std::vector<std::string> classVector(classes, classes + 5);
  std::vector<std::string> raceExplainVector(classesExplain, classesExplain + 5);
  return DisplayChoise(classVector, selectedClasses, "Class", raceExplainVector);
}

void moreInfoChoise(std::vector<std::string> arrayChoose, std::string choiseWhat, std::string input, std::vector<std::string> arrayExplainChoise)
{
  if (input == "1")
  {
    bool choiceExist;
    std::string inputChoise;

    while (!choiceExist)
    {
      std::cout << std::string(20, '\n');
      std::cout << "Which " + choiseWhat + " do you want to know more about?" << std::endl;
      for (int i = 0; i < arrayChoose.size(); i++)
      {
        std::cout << arrayChoose[i] << "\n";
      }

      std::cin >> inputChoise;
      choiceExist = std::find(arrayChoose.begin(), arrayChoose.end(), inputChoise) != arrayChoose.end();

      if (choiceExist)
      {
        if (choiseWhat == "Race")
        {
          if (inputChoise == "Human")
          {
            std::cout << "Humans are the most basic ass choise" << std::endl;
          }
          else if (inputChoise == "High Elves")
          {
            std::cout << "High elves are graceful, intelligent beings, with a greater capacity for intelligence than most humanoid races while also possessing an agility comparable with their elven kin. However they are not as musceler as the humaoid races." << std::endl;
          }
          else if (inputChoise == "Dwarfes")
          {
            std::cout << "Dwarves are short and stocky, but as heavy as a human. They are broad and stable creatures, perfectly suited to working close to the earth but as a consequnce they are . Their thick fingers are capable of surprisingly fine manipulations, while their strength allows them to dig through all but the hardest stone." << std::endl;
          }
          else if (inputChoise == "Orc")
          {
            std::cout << "Orcs are savage humanoids with green skin and a brutish appearance. They have no faculty for magic and lack both intelligence and agility, but are strong and capable warriors." << std::endl;
          }
          else if (inputChoise == "Dark Elves")
          {
            std::cout << "A member of a race of elves that is evil, has a dark skin and/or lives in dark places. As the other elf kin, the Dark Elves have confidents in thier extrene agility, while their phisical strength and defensive capabilities are a bit lacking. " << std::endl;
          }
        }

        if (choiseWhat == "Class")
        {
        }
      }

      std::cout << "You did not write an appropiate answer, try again." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
    }
  }
}

std::string Creature::raceDisplayChoice()
{
  std::string races[5] = {"Human", "High Elves", "Dwarfes", "Orc", "Dark Elves"};
  std::string raceExplain[5] = {
      "Strength: +1, Hp: +1, Inteligence: +2 | Mp: -2, Defence: -2",
      "Inteligence: +3, Mp: +4, Speed: +2 | Strength: -4, Hp: -1 and Defence: -3  ",
      "Strength: +2, Hp: +2, Defence: +2 | Mp : -3, Speed: -3 Inteligence: -1",
      "Strength: +6, Hp: +4 Defence: +1| Mp : -5, Speed: -5 Inteligence: -4 ",
      " Inteligence: +2, Mp: +1, Speed: +6 | Strength: -3 and Defence: -4 "};

  std::string selectedRace;
  std::vector<std::string> raceVector(races, races + 5);
  std::vector<std::string> raceExplainVector(raceExplain, raceExplain + 5);

  return DisplayChoise(raceVector, selectedRace, "Race", raceExplainVector);
}

std::string Creature::DisplayChoise(std::vector<std::string> arrayChoose, std::string choiseWhat, std::string input, std::vector<std::string> arrayExplainChoise)
{
  bool exists;

  while (!exists)
  {
    std::cout << std::string(20, '\n');
    std::cout << "Choose one of the avaliable " + choiseWhat + "." << std::endl;
    std::cout << "For more Infomation about one " + choiseWhat + ". Press : 1 " << std::endl
              << std::endl;

    for (int i = 0; i < arrayChoose.size(); i++)
    {
      std::cout << arrayChoose[i] << " - " << arrayExplainChoise[i] << "\n";
    }

    std::cin >> input;

    // !Mer info om valen
    moreInfoChoise(arrayChoose, choiseWhat, input, arrayExplainChoise);

    exists = std::find(arrayChoose.begin(), arrayChoose.end(), input) != arrayChoose.end();

    if (exists)
    {
      std::cout << "You choose the " + choiseWhat + ": " + input << std::endl;
      std::cout << "Press any button to continue..." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
      return input;
    }

    std::cout << "You did not write an appropiate answer, try again." << std::endl;
    // !Clearar buffern i sin
    std::cin.clear();
    std::cin.sync();
    std::cin.get();
  }

  return "";
}
