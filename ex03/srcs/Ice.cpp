#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") { std::cout << "[Ice] constructor" << std::endl; }

Ice::Ice(const Ice &copy)
{
  std::cout << "[Ice] copy constructor" << std::endl;
  *this = copy;
}
Ice::~Ice() { std::cout << "[Ice] destructor" << std::endl; }

Ice &Ice::operator=(const Ice &other)
{
  std::cout << "[Ice] asignation operator" << std::endl;
  (void)other;
  return (*this);
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
