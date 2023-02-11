#include <iostream>
#include <string>
using namespace std;

void func()
{
  string hihi = "WOW A FUNCTION?!!??";
  cout << hihi << endl;
}

int main()
{
  int x = 199;
  string userFavoriteLang = "";
  string greeting = "Hello";

  std::cout << "Hello World" << std ::endl;
  //? Med o utan STD namespace
  cout << "Hello World Again" << endl;
  cout << "I am learning C++" << std ::endl;
  cout << "Whats your favorite programming lanugue?" << std ::endl;
  cin >> userFavoriteLang;
  cout << "ooooh, I don't know " << userFavoriteLang << endl;
  cout << "I'm " << x << " Years old btw" << endl;

  cout << greeting << endl;
  func();
  return 0;
}