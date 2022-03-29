#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &copy) : AMateria("cure") { *this = copy; }
Cure::~Cure() {}
Cure &Cure::operator=(const Cure &other)
{
  (void)other;
  return (*this);
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
