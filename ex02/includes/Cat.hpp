/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:20:51 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:45:36 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
  Brain *_brain;

public:
  Cat(void);
  Cat(const Cat &copy);
  virtual ~Cat(void);

  Cat &operator=(const Cat &cat);

  void makeSound() const;
  Brain *getIdeas() const;
  void printIdea(int num) const;
  void changeIdea(int num);
};

#endif
