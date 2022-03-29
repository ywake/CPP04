#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
  std::string _name;
  static const int _inventorySize = 4;
  AMateria *_inventory[_inventorySize];

public:
  Character();
  Character(std::string const &name);
  Character(Character const &copy);
  ~Character();

  Character &operator=(const Character &other);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  void printMaterias();
};

#endif
