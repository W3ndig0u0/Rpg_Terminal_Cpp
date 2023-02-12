#include <iostream>
#include <string>
#include "entity.cpp"

class Item : public Entity
{
public:
  // !Stats for every entitiy
  std::string rarity_;

  std::string getRarity() { return rarity_; }
  void setRarity(std::string rarity)
  {
    rarity_ = rarity;
  }

  // !vara specifik om vilken rarity det är
  Item(std::string rarity, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Entity(entityName, race, level, experience, hp, maxHp, strength, speed, defence)
  {
    rarity_ = rarity;
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
    return "Name: " + getEntityName() + ". Race: " + getRace() + ". maxHp: " + std::to_string(getMaxHp()) + ". Hp: " + std::to_string(getHp()) + ". Rarity: " + rarity_ + ". Level: " + std::to_string(getLevel()) + ". Experience: " + std::to_string(getExperience()) + ". Strength: " + std::to_string(getStrength()) + ". Speed: " + std::to_string(getSpeed()) + ". Defence: " + std::to_string(getDefence());
  }
};
