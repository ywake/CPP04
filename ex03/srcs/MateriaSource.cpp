#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
  for (size_t i = 0; i < _memorySize; i++) {
    _memory[i] = NULL;
  }
}

MateriaSource::MateriaSource(MateriaSource const &copy) { *this = copy; }

MateriaSource::~MateriaSource()
{
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] != NULL) {
      delete _memory[i];
    }
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
  if (this != &other) {
    for (size_t i = 0; i < _memorySize; i++) {
      if (_memory[i] != NULL) {
        delete _memory[i];
      }
      if (other._memory[i] != NULL) {
        _memory[i] = other._memory[i]->clone();
      } else {
        _memory[i] = NULL;
      }
    }
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] == NULL) {
      _memory[i] = m;
      return;
    }
  }
  delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] && _memory[i]->getType() == type) {
      return _memory[i]->clone();
    }
  }
  return NULL;
}

void MateriaSource::printMemory()
{
  std::cout << "memory: [ ";
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i]) {
      std::cout << _memory[i]->getType() << " ";
    } else {
      std::cout << "NULL ";
    }
  }
  std::cout << "]" << std::endl;
}
