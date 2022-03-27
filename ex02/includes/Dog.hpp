/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:51:12 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:34:07 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
  Brain *_brain;

public:
  Dog(void);
  Dog(const Dog &copy);
  virtual ~Dog(void);

  Dog &operator=(const Dog &dog);

  void makeSound() const;
  Brain *getIdeas() const;
  void printIdea(int num) const;
  void changeIdea(int num);
};

#endif
