#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : _type("undefined") {}
AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria(AMateria const &copy) { *this = copy; }
AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &materia)
{
  if (this != &materia) {
    _type = materia.getType();
  }
  return (*this);
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) { (void)target; };
