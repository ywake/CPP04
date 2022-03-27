#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
private:
protected:
  std::string _type;

public:
  AMateria();
  AMateria(std::string const &type);
  AMateria(AMateria const &copy);
  virtual ~AMateria();

  AMateria &operator=(AMateria const &materia);

  std::string const &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
