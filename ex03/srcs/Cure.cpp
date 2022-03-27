#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
  std::cout << "[Cure] constructor" << std::endl;
}

Cure::Cure(const Cure &copy)
{
  std::cout << "[Cure] copy constructor" << std::endl;
  *this = copy;
}
Cure::~Cure() { std::cout << "[Cure] destructor" << std::endl; }

Cure &Cure::operator=(const Cure &other)
{
  std::cout << "[Cure] asignation operator" << std::endl;
  (void)other;
  return (*this);
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
