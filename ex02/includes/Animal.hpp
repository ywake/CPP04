/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:32:10 by ywake             #+#    #+#             */
/*   Updated: 2022/03/27 16:57:42 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
private:
protected:
  std::string type;

public:
  Animal(void);
  Animal(Animal const &copy);
  virtual ~Animal(void);

  Animal &operator=(const Animal &other);

  std::string getType() const;

  virtual void makeSound() const = 0;
};

#endif
