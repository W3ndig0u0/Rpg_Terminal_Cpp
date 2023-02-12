#include <iostream>
#include <string>
#include "player.cpp"

class Menu
{
public:
  void menuStart();
  void playerInfo();

  void PlayGame();
  void showOption();
  void showInfo();
};

void Menu::menuStart()
{
  int inputOption;

  std::cout << "välkommen till Jings spel" << std::endl;
  // !Va i menyn till de tycker på start (3)
  while (inputOption != 1)
  {
    std::cout << std::string(1, '\n');
    std::cout << "Välj en av alternativen: " << std::endl;
    std::cout << "1. Spela spelet " << std::endl;
    std::cout << "2. Inställningar " << std::endl;
    std::cout << "3. Mer om spelet " << std::endl;
    std::cout << "4. Lämna spelet" << std::endl;

    std::cin >> inputOption;

    switch (inputOption)
    {
    case 1:
      playerInfo();
      break;

    case 2:
      showOption();
      break;

    case 3:
      showInfo();
      break;

    case 4:
      exit(0);
      break;

    default:
      std::cout << std::string(20, '\n');
      std::cout << "Ej giltig svar: " << std::endl;
      break;
    }
  }
}

void Menu::playerInfo()
{
  std::cout << std::string(20, '\n');

  // !Skapar för att det ska behålla spelarens egenskaper tills vi fårgar spelaren (början till spelet)
  std::string playerName;
  int playerAge;

  Player player(playerName, playerAge, 0);

  std::cout << "Vad är ditt namn?" << std::endl;
  std::cin >> playerName;
  player.setEntityName(playerName);

  std::cout << "Hur gammal är du?" << std::endl;
  std::cin >> playerAge;
  player.setAge(playerAge);

  std::cout << player.toString() << std::endl;

  if (player.legalAge(playerAge) == false)
  {
    std::cout << "Tryck på en knapp för att avsluta programmet" << std::endl;
    std::cin.get();
    // exit(0);
  }
}

void Menu::showOption()
{
  std::cout << std::string(20, '\n');
  std::cout << "OPTION:" << std::endl;
  std::cout << "“C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off.”:" << std::endl;

  std::cout << "Press any key to continue..." << std::endl;

  // !Clearar buffern i sin
  std::cin.clear();
  std::cin.sync();
  std::cin.get();
}

void Menu::showInfo()
{
  std::cout << std::string(20, '\n');

  std::cout << "INFO:" << std::endl;
  std::cout << "Spelet är en console rpg bla bla bla" << std::endl;
  std::cout << "Press any key to continue..." << std::endl;

  // !Clearar buffern i sin
  std::cin.clear();
  std::cin.sync();
  std::cin.get();
}