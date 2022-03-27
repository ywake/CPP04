#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
  std::cout << "[MateriaSource] default constructor" << std::endl;
  for (size_t i = 0; i < _memorySize; i++) {
    _memory[i] = NULL;
  }
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
  std::cout << "[MateriaSource] copy constructor" << std::endl;
  *this = copy;
}

MateriaSource::~MateriaSource()
{
  std::cout << "[MateriaSource] detstructor" << std::endl;
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] != NULL) {
      delete _memory[i];
    }
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
  std::cout << "[MateriaSource] asignation operator" << std::endl;
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
  std::cout << "[MateriaSource] Learn ";
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] == NULL) {
      _memory[i] = m;
      std::cout << m->getType() << " in slot " << i << std::endl;
      return;
    }
  }
  std::cout << "failed. Memory is full." << std::endl;
  delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
  std::cout << "[MateriaSource] Create ";
  for (size_t i = 0; i < _memorySize; i++) {
    if (_memory[i] && _memory[i]->getType() == type) {
      std::cout << type << std::endl;
      return _memory[i]->clone();
    }
  }
  std::cout << "failed. The type is not learned." << std::endl;
  return NULL;
}
