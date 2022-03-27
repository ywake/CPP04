/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:26:10 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:42:25 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <string>

std::string getRandomString()
{
  std::string str;
  str = "";
  for (size_t i = 0; i < 3; i++)
    str += "abcdefghijklmnopqrstuvwxyz"[std::rand() % 26];
  return str;
}

Brain::Brain()
{
  std::cout << "[Brain] constructor" << std::endl;

  for (size_t i = 0; i < IDEAS_NUM; i++) {
    _ideas[i] = getRandomString();
  }
}

Brain::~Brain() { std::cout << "[Brain] destructor" << std::endl; }

Brain::Brain(Brain const &copy)
{
  std::cout << "[Brain] copy constructor" << std::endl;
  *this = copy;
}

Brain &Brain::operator=(const Brain &other)
{
  std::cout << "[Brain] operator=" << std::endl;
  if (this != &other) {
    for (size_t i = 0; i < IDEAS_NUM; i++) {
      _ideas[i] = other.getIdea(i);
    }
  }
  return *this;
}

const std::string &Brain::getIdea(int index) const
{
  return _ideas[index % IDEAS_NUM];
}

void Brain::setIdea(int index, std::string &idea)
{
  _ideas[index % IDEAS_NUM] = idea;
}
