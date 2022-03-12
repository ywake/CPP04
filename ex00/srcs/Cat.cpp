/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:43 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 13:22:00 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal()
{
  std::cout << "[Cat] constructor" << std::endl;
  this->type = "Cat";
}

Cat::~Cat(void) { std::cout << "[Cat] destructor" << std::endl; }

void Cat::makeSound() const { std::cout << "[Cat] Meow" << std::endl; }
