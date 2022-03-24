/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:43 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:46:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal(), _brain(new Brain())
{
  std::cout << "[Cat] constructor" << std::endl;
  this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*copy.getIdeas()))
{
  std::cout << "[Cat] copy constructor" << std::endl;
  this->type = "Cat";
}

Cat::~Cat(void)
{
  std::cout << "[Cat] destructor" << std::endl;
  delete _brain;
}

Cat &Cat::operator=(const Cat &cat)
{
  if (this != &cat) {
    type = cat.type;
    *(this->_brain) = *(cat._brain);
  }
  return (*this);
}

void Cat::makeSound() const { std::cout << "[Cat] Meow" << std::endl; }

Brain *Cat::getIdeas() const { return _brain; }

void Cat::printIdea(int num) const
{
  std::cout << _brain->getIdea(num) << std::endl;
}

void Cat::changeIdea(int num)
{
  std::string str = getRandomString();
  _brain->setIdea(num, str);
}
