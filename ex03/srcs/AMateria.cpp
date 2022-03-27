#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : _type("undefined")
{
  std::cout << "[AMateria] default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
  std::cout << "[AMateria] constructor " << type << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
  std::cout << "[AMateria] copy constructor" << std::endl;
  *this = copy;
}

AMateria::~AMateria() { std::cout << "[AMateria] detstructor" << std::endl; }

AMateria &AMateria::operator=(AMateria const &materia)
{
  std::cout << "[AMateria] asignation operator" << std::endl;
  if (this != &materia) {
    _type = materia.getType();
  }
  return (*this);
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) { (void)target; };
