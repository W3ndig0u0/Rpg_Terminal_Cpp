#include <iostream>
#include <string>
#include "player.cpp"

class CharacterCreation
{
public:
  CharacterCreation();
  void raceStats(Player player);
};

CharacterCreation::CharacterCreation()
{
  std::cout << std::string(20, '\n');
  std::cout << "Du ska nu skapa din karaktär som du ska köra med!" << std::endl;

  // !Skapar för att det ska behålla spelarens egenskaper tills vi fårgar spelaren (början till spelet)
  std::string playerName;
  int playerAge;

  Player player("Class", playerAge, 1, 1, 1, 1, playerName, "Human", 1, 1, 1, 1, 1, 1);

  std::cout << "Vad ska din karaktär heta?" << std::endl;
  std::cin >> playerName;
  player.setEntityName(playerName);

  std::cout << "Hur gammal ska din karaktär vara? " << std::endl;
  std::cin >> playerAge;
  player.setAge(playerAge);

  player.setRace(player.raceDisplayChoice());
  player.setClass(player.classDisplayChoice());

  std::string classes[5] = {"Knight", "Wizard", "Rogue", "Rangers", "Clerics"};
  std::string classesExplain[5] = {

      "+[Uncommon] Sword, +[Common]Armor, +2x [Common] Hp Potions ",
      "+[Uncommon] Magic Wand, +[Common] Robe, +2x [Common] Mp Potions ",
      "+[Uncommon] Dagger, +[Common] Lesser Bow, +[Common] Thief Hood, +2x [Common] Arrows ",
      "+[Uncommon] Long Bow, +[Common] Cloak, +10x [Common] Arrows + 1x [Common] Hp Potions, +1x [Common] Mp Potions",
      "+[Uncommon] Handbook, +[Common] Small Mace, +[Common] Robe, +2x [Common] Mp Potions"};

  raceStats(player);

  std::cout << std::string(100, '\n');
  std::cout << player.toString() << std::endl;
}

void setStats(Player player)
{
  player.setMaxHp(1);
  player.setMaxMp(1);
  player.setStrength(6);
  player.setSpeed(10);
  player.setDefence(7);
  player.setIntelligence(7);
}

void CharacterCreation::raceStats(Player player)
{
  std::cout << player.toString() << std::endl;

  if (player.getRace() == "Human")
  {
    player.setStrength(6);
    player.setMaxHp(6);
    player.setIntelligence(6);
    player.setMaxMp(3);
    player.setDefence(4);
  }
  else if (player.getRace() == "High-Elves")
  {
    player.setIntelligence(8);
    player.setMaxMp(9);
    player.setSpeed(7);
    player.setMaxHp(4);
    player.setStrength(1);
    player.setDefence(2);
  }
  else if (player.getRace() == "Dwarfes")
  {
    player.setStrength(7);
    player.setMaxHp(7);
    player.setDefence(7);
    player.setMaxMp(2);
    player.setSpeed(3);
    player.setIntelligence(2);
  }
  else if (player.getRace() == "Orc")
  {
    player.setStrength(11);
    player.setMaxHp(9);
    player.setDefence(6);
    player.setMaxMp(0);
    player.setSpeed(1);
    player.setIntelligence(0);
  }
  else if (player.getRace() == "Dark-Elves")
  {
    player.setStrength(3);
    player.setDefence(1);
    player.setMaxMp(6);
    player.setMaxHp(4);
    player.setSpeed(10);
    player.setIntelligence(7);
  }
}