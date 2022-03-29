#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void subject()
{
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
}

void myTest()
{
  std::cout << "\nMy Test" << std::endl;
  IMateriaSource *bag = new MateriaSource();
  bag->printMemory();

  // learn
  std::cout << "learn ice * 4" << std::endl;
  bag->learnMateria(NULL);
  bag->learnMateria(new Cure());
  for (size_t i = 0; i < 3; i++) {
    bag->learnMateria(new Ice());
  }
  bag->printMemory();

  // over learn
  std::cout << "try learn cure" << std::endl;
  bag->learnMateria(new Cure());
  bag->printMemory();
  bag->learnMateria(NULL);

  std::cout << "init characters" << std::endl;
  ICharacter *cloud = new Character("Cloud");
  ICharacter *sephiroth = new Character("Sephiroth");
  cloud->printMaterias();
  sephiroth->printMaterias();

  std::cout << "characters equip materia" << std::endl;
  cloud->equip(NULL);
  cloud->equip(bag->createMateria("ice"));
  cloud->equip(bag->createMateria("cure"));
  for (size_t i = 0; i < 4; i++) {
    sephiroth->equip(bag->createMateria("ice"));
  }
  sephiroth->equip(bag->createMateria("cure"));
  sephiroth->equip(NULL);
  cloud->printMaterias();
  sephiroth->printMaterias();

  std::cout << "character unequip materia" << std::endl;
  for (size_t i = 0; i < 100; i++) {
    cloud->unequip(i);
  }
  cloud->printMaterias();

  std::cout << "character use materia" << std::endl;
  for (size_t i = 0; i < 100; i++) {
    sephiroth->use(i, *cloud);
  }

  delete cloud;
  delete sephiroth;
  delete bag;
}

int main(void)
{
  subject();
  myTest();
}
