/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:43 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 15:42:47 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
  std::cout << "[WrongCat] constructor" << std::endl;
  this->type = "WrongCat";
}

WrongCat::~WrongCat(void) { std::cout << "[WrongCat] destructor" << std::endl; }

void WrongCat::makeSound() const
{
  std::cout << "[WrongCat] Meow" << std::endl;
}
