#include "Character.hpp"

#include <iostream>

Character::Character() : _name("NoName")
{
  std::cout << "[Character] default constructor" << std::endl;
  for (size_t i = 0; i < _inventorySize; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(std::string const &name) : _name(name)
{
  std::cout << "[Character] constructor " << name << std::endl;
  for (size_t i = 0; i < _inventorySize; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(Character const &copy)
{
  std::cout << "[Character] copy constructor" << std::endl;
  *this = copy;
}

Character::~Character()
{
  std::cout << "[Character] detstructor" << std::endl;
  for (size_t i = 0; i < _inventorySize; i++) {
    if (_inventory[i] != NULL) {
      delete _inventory[i];
    }
  }
}

Character &Character::operator=(Character const &other)
{
  std::cout << "[Character] asignation operator" << std::endl;
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
  std::cout << "[" << _name << "] Equip ";
  for (size_t i = 0; i < _inventorySize; i++) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      std::cout << m->getType() << " in slot " << i << std::endl;
      return;
    }
  }
  std::cout << "failed. Inventory is full." << std::endl;
  delete m;
}

void Character::unequip(int idx)
{
  std::cout << "[" << _name << "] Unequip ";
  if (idx < 0 || _inventorySize <= idx || _inventory[idx] == NULL) {
    std::cout << "failed." << std::endl;
    return;
  }
  std::cout << _inventory[idx]->getType() << " from slot " << idx << std::endl;
  delete _inventory[idx];
  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
  std::cout << "[" << _name << "] ";
  if (idx < 0 || _inventorySize <= idx || _inventory[idx] == NULL) {
    std::cout << "Failed to use materia in slot " << idx << std::endl;
    return;
  }
  std::cout << "Use materia in slot " << idx << std::endl;
  _inventory[idx]->use(target);
}
