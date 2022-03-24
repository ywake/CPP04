/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:31:56 by ywake             #+#    #+#             */
/*   Updated: 2022/03/21 00:56:24 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) : type("animal")
{
  std::cout << "[Animal] constructor" << std::endl;
}

Animal::Animal(Animal const &copy)
{
  std::cout << "[Animal] copy constructor" << std::endl;
  *this = copy;
}

Animal::~Animal(void) { std::cout << "[Animal] destructor" << std::endl; }

Animal &Animal::operator=(const Animal &other)
{
  std::cout << "[Animal] operator=" << std::endl;
  if (this != &other) {
    type = other.getType();
  }
  return *this;
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const
{
  std::cout << "[Animal] makeSound" << std::endl;
}
