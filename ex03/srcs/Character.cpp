#include "Character.hpp"

#include <iostream>

Character::Character() : _name("NoName")
{
  for (size_t i = 0; i < _inventorySize; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(std::string const &name) : _name(name)
{
  for (size_t i = 0; i < _inventorySize; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(Character const &copy) { *this = copy; }

Character::~Character()
{
  for (size_t i = 0; i < _inventorySize; i++) {
    if (_inventory[i] != NULL) {
      delete _inventory[i];
    }
  }
}

Character &Character::operator=(Character const &other)
{
  if (this != &other) {
    _name = other.getName();
    for (size_t i = 0; i < _inventorySize; i++) {
      if (_inventory[i] != NULL) {
        delete _inventory[i];
      }
      if (other._inventory[i] != NULL) {
        _inventory[i] = other._inventory[i]->clone();
      } else {
        _inventory[i] = NULL;
      }
    }
  }
  return (*this);
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m)
{
  for (size_t i = 0; i < _inventorySize; i++) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      return;
    }
  }
  delete m;
}

void Character::unequip(int idx)
{
  if (idx < 0 || _inventorySize <= idx || _inventory[idx] == NULL) {
    return;
  }
  delete _inventory[idx];
  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
  if (idx < 0 || _inventorySize <= idx || _inventory[idx] == NULL) {
    return;
  }
  _inventory[idx]->use(target);
}

void Character::printMaterias()
{
  std::cout << _name << ": [ ";
  for (size_t i = 0; i < _inventorySize; i++) {
    if (_inventory[i]) {
      std::cout << _inventory[i]->getType() << " ";
    } else {
      std::cout << "NULL ";
    }
  }
  std::cout << "]" << std::endl;
}
