/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:43 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:41:33 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) : Animal(), _brain(new Brain())
{
  std::cout << "[Dog] constructor" << std::endl;
  this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy.getIdeas()))
{
  std::cout << "[Dog] copy constructor" << std::endl;
  this->type = "Dog";
}

Dog::~Dog(void)
{
  std::cout << "[Dog] destructor" << std::endl;
  delete _brain;
}

Dog &Dog::operator=(const Dog &dog)
{
  if (this != &dog) {
    type = dog.type;
    *(this->_brain) = *(dog._brain);
  }
  return (*this);
}

void Dog::makeSound() const { std::cout << "[Dog] Bow wow" << std::endl; }

Brain *Dog::getIdeas() const { return _brain; }

void Dog::printIdea(int num) const
{
  std::cout << _brain->getIdea(num) << std::endl;
}

void Dog::changeIdea(int num)
{
  std::string str = getRandomString();
  _brain->setIdea(num, str);
}
