/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:36:49 by ywake             #+#    #+#             */
/*   Updated: 2022/03/27 16:36:08 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define DOGS_NUM (50)

void subject()
{
  Animal *array[DOGS_NUM * 2];
  for (size_t i = 0; i < DOGS_NUM * 2; i++) {
    if (i < DOGS_NUM) {
      array[i] = new Dog();
    } else {
      array[i] = new Cat();
    }
  }
  for (size_t i = 0; i < DOGS_NUM * 2; i++) {
    delete array[i];
  }
}

void deepCopy()
{
  Dog dog;
  std::cout << "[Info] dog: ";
  dog.printIdea(0);

  Dog dog1;
  std::cout << "[Info] dog1: ";
  dog1.printIdea(0);

  Dog dog2(dog1);
  std::cout << "[Info] dog2: ";
  dog2.printIdea(0);

  Dog dog3;
  dog3 = dog2;
  dog2.changeIdea(0);
  std::cout << "[Info] dog2 changed his Idea." << std::endl;
  std::cout << "[Info] dog3: ";
  dog3.printIdea(0);
  std::cout << "[Info] dog2: ";
  dog2.printIdea(0);

  Cat cat;
  std::cout << "[Info] cat: ";
  cat.printIdea(0);

  Cat cat1;
  std::cout << "[Info] cat1: ";
  cat1.printIdea(0);

  Cat cat2(cat1);
  std::cout << "[Info] cat2: ";
  cat2.printIdea(0);

  Cat cat3;
  cat3 = cat2;
  cat2.changeIdea(0);
  std::cout << "[Info] cat2 changed her Idea." << std::endl;
  std::cout << "[Info] cat3: ";
  cat3.printIdea(0);
  std::cout << "[Info] cat2: ";
  cat2.printIdea(0);
}

int main(void)
{
  subject();
  deepCopy();
}
