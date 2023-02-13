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
  Item(std::string rarity, std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int speed, int defence) : Entity(entityName, race, level, experience, hp, maxHp, strength, defence)
  {
    rarity_ = rarity;
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
    return "[" + rarity_ + "] Name: " + getEntityName() + " Race: " + getRace() + ". maxDurability: " + std::to_string(getMaxHp()) + ". Durability: " + std::to_string(getHp()) + ". Level: " + std::to_string(getLevel()) + ". Experience: " + std::to_string(getExperience()) + ". Strength: " + std::to_string(getStrength()) + ". Defence: " + std::to_string(getDefence());
  }
};
