/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:36:49 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 16:12:38 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << "\n{" << std::endl;
  {
    Dog dog;
    const Dog copyDog = dog;
    copyDog.makeSound();
  }
  std::cout << "}" << std::endl;

  std::cout << "\n{" << std::endl;
  {
    Cat cat;
    const Cat copyCat(cat);
    copyCat.makeSound();
  }
  std::cout << "}" << std::endl;

  std::cout << "\ndelete" << std::endl;
  delete meta;
  delete j;
  delete i;

  std::cout << "\n{" << std::endl;
  {
    WrongAnimal *wrongCat = new WrongCat();
    wrongCat->makeSound();
    delete wrongCat;
  }
  std::cout << "}" << std::endl;
}
