#include <iostream>
#include <string>

class Entity
{
  // !Stats for every entitiy
  std::string entityName_;
  std::string race_;
  int level_;
  int experience_;
  int hp_;
  int maxHp_;
  int strength_;
  int defence_;

public:
  Entity(std::string entityName, std::string race, int level, int experience, int hp, int maxHp, int strength, int defence)
      : entityName_(entityName), race_(race), level_(level), experience_(experience), hp_(hp), maxHp_(maxHp), strength_(strength), defence_(defence)
  {
  }

  // !Gör en string som innehåller variablerna
  std::string toString()
  {
    return "Name: " + entityName_ + ". Race: " + race_ + ". maxHp: " + std::to_string(maxHp_) + ". Hp: " + std::to_string(hp_) + ". Level: " + std::to_string(level_) + ". Experience: " + std::to_string(experience_) + ". Strength: " + std::to_string(strength_) + ". Speed: " + ". Defence: " + std::to_string(defence_);
  }

  // !Getter och setter
  std::string getEntityName() { return entityName_; }
  void setEntityName(std::string realEntityName)
  {
    entityName_ = realEntityName;
  }

  std::string getRace() { return race_; }
  void setRace(std::string race)
  {
    race_ = race;
  }

  int getLevel() { return level_; }
  void setLevel(int level)
  {
    level_ = level;
  }

  int getExperience() { return experience_; }
  void setExperience(int experience)
  {
    experience_ = experience;
  }

  int getHp() { return hp_; }
  void setHp(int hp)
  {
    hp_ = hp;
  }

  int getMaxHp() { return maxHp_; }
  void setMaxHp(int maxHp)
  {
    maxHp_ = maxHp;
  }

  int getStrength() { return strength_; }
  void setStrength(int strength)
  {
    strength_ = strength;
  }

  int getDefence() { return defence_; }
  void setDefence(int defence)
  {
    defence_ = defence;
  }
  
};