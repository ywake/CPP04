/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:32:10 by ywake             #+#    #+#             */
/*   Updated: 2022/03/12 16:13:41 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
private:
protected:
  std::string type;

public:
  WrongAnimal(void);
  WrongAnimal(WrongAnimal const &copy);
  virtual ~WrongAnimal(void);

  WrongAnimal &operator=(const WrongAnimal &other);

  std::string getType() const;

  void makeSound() const;
};

#endif
