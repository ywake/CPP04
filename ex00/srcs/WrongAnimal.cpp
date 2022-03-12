/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:31:56 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 15:26:58 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) : type("Wronganimal")
{
  std::cout << "[WrongAnimal] constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
  std::cout << "[WrongAnimal] copy constructor" << std::endl;
  *this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
  std::cout << "[WrongAnimal] destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
  std::cout << "[WrongAnimal] operator=" << std::endl;
  if (this != &other) {
    type = other.getType();
  }
  return *this;
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const
{
  std::cout << "[WrongAnimal] makeSound" << std::endl;
}
