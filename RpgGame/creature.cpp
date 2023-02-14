#include <iostream>
#include <string>
#include <algorithm>

#include "entity.cpp"

class Creature : public Entity
{
  // !Stats for every entitiy
  std::string class_;
  int age_;
  int mp_;
  int speed_;
  int maxMp_;
  int intelligence_;

public:
  std::string classDisplayChoice();
  std::string raceDisplayChoice();
  std::string DisplayChoise(std::string arrayChoose[], std::string choiseWhat, std::string input, std::string arrayExplainChoise[]);

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

  int getIntelligence() { return intelligence_; }
  void setIntelligence(int intelligence)
  {
    intelligence_ = intelligence;
  }

  int getSpeed() { return speed_; }
  void setSpeed(int speed)
  {
    speed_ = speed;
  }

  // ?Inventory...
  // Inventory inventory;

  Creature(std::string rpgClass, int age, int intelligence, int mp, int maxMp, int speed, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int defence) : Entity(entityName, race, level, experience, hp, maxHp, strength, defence)
  {
    class_ = rpgClass;
    age_ = age;
    intelligence_ = intelligence;
    mp_ = mp;
    maxMp_ = maxMp;
    speed_ = speed;
    setEntityName(entityName);
    setRace(race);
    setLevel(level);
    setExperience(experience);
    setHp(hp);
    setMaxHp(maxHp);
    setStrength(strength);
    setDefence(defence);
  }

  std::string toString()
  {
    return "Name: " + getEntityName() + ". Race: " + getRace() + ". Class: " + class_ + ". Age: " + std::to_string(age_) + ". MaxHp: " + std::to_string(getMaxHp()) + ". Hp: " + std::to_string(getHp()) + ". \nMaxMp: " + std::to_string(maxMp_) + ". Mp: " + std::to_string(mp_) + ". \nStrength: " + std::to_string(getStrength()) + ". Speed: " + std::to_string(getSpeed()) + ". Defence: " + std::to_string(getDefence()) + ". \nLevel: " + std::to_string(getLevel()) + ". Experience: " + std::to_string(getExperience());
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

  return DisplayChoise(classes, "Class", selectedClasses, classesExplain);
}

std::string Creature::raceDisplayChoice()
{
  std::string races[5] = {"Human", "High-Elves", "Dwarfes", "Orc", "Dark-Elves"};
  std::string raceExplain[5] = {
      "Strength: +1, Hp: +1, Inteligence: +1 | Mp: -2, Defence: -1",
      "Inteligence: +3, Mp: +4, Speed: +2 | Strength: -4, Hp: -1 and Defence: -3  ",
      "Strength: +2, Hp: +2, Defence: +2 | Mp: -3, Speed: -2 Inteligence: -3",
      "Strength: +6, Hp: +4 Defence: +1 | Mp: -5, Speed: -4 Inteligence: -4 ",
      " Inteligence: +2, Mp: +1, Speed: +5 | Strength: -2, Defence: -4, Hp: -1"};

  std::string selectedRace;
  return DisplayChoise(races, "Race", selectedRace, raceExplain);
}

void moreInfoChoise(std::string arrayChoose[], std::string choiseWhat, std::string input)
{
  bool choiceExist;
  std::string inputChoise;

  while (!choiceExist)
  {
    std::cout << std::string(100, '\n');
    std::cout << "Which " + choiseWhat + " do you want to know more about?" << std::endl;
    for (int i = 0; i < 5; i++)
    {
      std::cout << arrayChoose[i] << "\n";
    }

    std::cin >> inputChoise;

    for (int i = 0; i < 5; i++)
    {
      if (arrayChoose[i] == inputChoise)
      {
        choiceExist = true;
      }
    }

    if (!choiceExist)
    {
      std::cout << "You did not write an appropiate answer, try again." << std::endl;
      std::cout << "Press The ENTER key to continue..." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
    }

    else if (choiceExist)
    {
      std::cout << std::string(100, '\n');

      if (choiseWhat.compare("Race") == 0)
      {
        if (inputChoise.compare("Human") == 0)
        {
          std::cout << "In the reckonings of most worlds, humans are the youngest of the common races, late to arrive on the world scene and short-lived in comparison to dwarves, elves, and dragons. Perhaps it is because of their shorter lives that they strive to achieve as much as they can in the years they are given. Or maybe they feel they have something to prove to the elder races, and that’s why they build their mighty empires on the foundation of conquest and trade. Whatever drives them, humans are the innovators, the achievers, and the pioneers of the worlds." << std::endl;
        }
        else if (inputChoise.compare("High-Elves") == 0)
        {
          std::cout << "High elves are graceful, intelligent beings, with a greater capacity for intelligence than most humanoid races while also possessing an agility comparable with their elven kin. However they are not as musceler as the humaoid races." << std::endl;
        }
        else if (inputChoise.compare("Dwarfes") == 0)
        {
          std::cout << "Dwarves are short and stocky, but as heavy as a human. They are broad and stable creatures, perfectly suited to working close to the earth but as a consequnce they are . Their thick fingers are capable of surprisingly fine manipulations, while their strength allows them to dig through all but the hardest stone." << std::endl;
        }
        else if (inputChoise.compare("Orc") == 0)
        {
          std::cout << "Orcs are savage humanoids with green skin and a brutish appearance. They have no faculty for magic and lack both intelligence and agility, but are strong and capable warriors." << std::endl;
        }
        else if (inputChoise.compare("Dark-Elves") == 0)
        {
          std::cout << "A member of a race of elves that is evil, has a dark skin and/or lives in dark places. As the other elf kin, the Dark Elves have confidents in thier extrene agility, while their phisical strength and defensive capabilities are a bit lacking. " << std::endl;
        }
      }

      else if (choiseWhat.compare("Class") == 0)

      {
        if (inputChoise.compare("Knight") == 0)
        {
          std::cout << "Knights are warriors who pledge service to rulers, religious orders, and noble causes. A knight's Alignment determines the extent to which a pledge is honored. Whether undertaking a quest or patrolling a realm, a knight often travels with an Entourage that includes squires and Hirelings who are commoners" << std::endl;
        }
        else if (inputChoise.compare("Wizard") == 0)
        {
          std::cout << "Wizards are supreme magic-users, defined and united as a class by the spells they cast. Drawing on the subtle weave of magic that permeates the cosmos, wizards cast spells of explosive fire, arcing lightning, subtle deception, and brute-force mind control. Their magic conjures monsters from other planes of existence, glimpses the future, or turns slain foes into zombies. Their mightiest spells change one substance into another, call meteors down from the sky, or open portals to other worlds." << std::endl;
        }
        else if (inputChoise.compare("Rogue") == 0)
        {
          std::cout << "Every town and city has its share of rogues. Most of them live up to the worst stereotypes of the class, making a living as burglars, assassins, cutpurses, and con artists. Often, these scoundrels are organized into thieves’ guilds or crime families. Plenty of rogues operate independently, but even they sometimes recruit apprentices to help them in their scams and heists. A few rogues make an honest living as locksmiths, investigators, or exterminators, which can be a dangerous job in a world where dire rats—and wererats—haunt the sewers." << std::endl;
        }
        else if (inputChoise.compare("Rangers") == 0)
        {
          std::cout << "Warriors of the wilderness, rangers specialize in hunting the monsters that threaten the edges of civilization—humanoid raiders, rampaging beasts and monstrosities, terrible giants, and deadly dragons. They learn to track their quarry as a predator does, moving stealthily through the wilds and hiding themselves in brush and rubble. Rangers focus their combat training on techniques that are particularly useful against their specific favored foes." << std::endl;
        }
        else if (inputChoise.compare("Clerics") == 0)
        {
          std::cout << "Clerics combine the helpful magic of healing and inspiring their allies with spells that harm and hinder foes. They can provoke awe and dread, lay curses of plague or poison, and even call down flames from heaven to consume their enemies. For those evildoers who will benefit most from a mace to the head, clerics depend on their combat training to let them wade into melee with the power of the gods on their side." << std::endl;
        }
      }

      std::cout << "Press The ENTER key to continue..." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
    }
  }
}

std::string Creature::DisplayChoise(std::string arrayChoose[], std::string choiseWhat, std::string input, std::string arrayExplainChoise[])
{
  bool exists;

  while (!exists)
  {
    std::cout << std::string(100, '\n');
    std::cout << "Choose one of the avaliable " + choiseWhat + "." << std::endl;
    std::cout << "For more Infomation about one " + choiseWhat + ". Press : 1" << std::endl
              << std::endl;

    for (int i = 0; i < 5; i++)
    {
      std::cout << arrayChoose[i] << " - " << arrayExplainChoise[i] << "\n";
    }

    std::cin >> input;
    // !Mer info om valen

    for (int i = 0; i < 5; i++)
    {
      if (arrayChoose[i] == input)
      {
        exists = true;
      }
    }

    if (input == "1")
    {
      moreInfoChoise(arrayChoose, choiseWhat, input);
    }

    if (exists)
    {
      std::cout << "You chose the " + choiseWhat + ": " + input << std::endl;
      std::cout << "Press The ENTER key to continue..." << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
      return input;
    }

    else if (input != "1" || !exists)
    {
      std::cout << "You did not write an appropiate answer, try again." << std::endl;
      std::cout << "Press The ENTER key to continue..." << std::endl;
      std::cout << input << std::endl;
      // !Clearar buffern i sin
      std::cin.clear();
      std::cin.sync();
      std::cin.get();
    }
  }

  return input;
}