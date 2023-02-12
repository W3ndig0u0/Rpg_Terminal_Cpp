#include <iostream>
#include <string>
#include "player.cpp"

class CharacterCreation
{
public:
  CharacterCreation();
};

CharacterCreation::CharacterCreation()
{
  std::cout << std::string(20, '\n');
  std::cout << "Du ska nu skapa din karaktär som du ska köra med!" << std::endl;

  // !Skapar för att det ska behålla spelarens egenskaper tills vi fårgar spelaren (början till spelet)
  std::string playerName;
  int playerAge;

  Player player("Class", playerAge, 1, 1, playerName, "Human", 1, 1, 1, 1, 1, 1, 1);

  std::cout << "Vad ska din karaktär heta?" << std::endl;
  std::cin >> playerName;
  player.setEntityName(playerName);

  std::cout << "Hur gammal ska din karaktär vara?" << std::endl;
  std::cin >> playerAge;
  player.setAge(playerAge);

  player.setRace(player.raceDisplayChoice());
  player.setClass(player.classDisplayChoice());

  std::cout << player.toString() << std::endl;
}