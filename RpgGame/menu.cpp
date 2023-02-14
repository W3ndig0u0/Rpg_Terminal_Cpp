#include <iostream>
#include <string>
#include "characterCreation.cpp"

class Menu
{
public:
  void menuStart();
  void playerInfo();

  void playGame();
  void showOption();
  void showInfo();
  void menuChoise(int inputOption);
};

void Menu::menuStart()
{
  int inputOption = 0;

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
    menuChoise(inputOption);
  }
}

void Menu::menuChoise(int inputOption)
{
  switch (inputOption)
  {
  case 1:
    std::cout << "AA" << std::endl;
    Menu::playGame();
    break;

  case 2:
    Menu::showOption();
    break;

  case 3:
    Menu::showInfo();
    break;

  case 4:
    exit(0);
    break;

  default:
    std::cout << std::string(100, '\n');
    std::cout << "Ej giltig svar: " << std::endl;
    break;
  }
}

// !Clearar buffern i sin
void bufferCin()
{
  std::cin.clear();
  std::cin.sync();
  std::cin.get();
}

void Menu::playGame()
{
  CharacterCreation cc;
}

void Menu::showOption()
{
  std::cout << std::string(100, '\n');
  std::cout << "OPTION:" << std::endl;
  std::cout << "“C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off.”:" << std::endl;

  std::cout << "Press any key to continue..." << std::endl;

  bufferCin();
}

void Menu::showInfo()
{
  std::cout << std::string(100, '\n');

  std::cout << "INFO:" << std::endl;
  std::cout << "Spelet är en console rpg bla bla bla" << std::endl;
  std::cout << "Press any key to continue..." << std::endl;

  // !Clearar buffern i sin
  std::cin.clear();
  std::cin.sync();
  std::cin.get();
}