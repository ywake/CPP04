#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
private:
  static const int _memorySize = 4;
  AMateria *_memory[_memorySize];

public:
  MateriaSource();
  MateriaSource(MateriaSource const &copy);
  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &other);

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);
};

#endif
