/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:43 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 13:09:10 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal()
{
  std::cout << "[Dog] constructor" << std::endl;
  this->type = "Dog";
}

Dog::~Dog(void) { std::cout << "[Dog] destructor" << std::endl; }

void Dog::makeSound() const { std::cout << "[Dog] Bow wow" << std::endl; }
