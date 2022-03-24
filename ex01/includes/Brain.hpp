/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:25:41 by ywake             #+#    #+#             */
/*   Updated: 2022/03/25 04:42:32 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define IDEAS_NUM (100)

class Brain
{
private:
  std::string _ideas[IDEAS_NUM];

public:
  Brain();
  Brain(Brain const &copy);
  ~Brain();

  Brain &operator=(const Brain &other);

  const std::string &getIdea(int index) const;
  void setIdea(int index, std::string &idea);
};

std::string getRandomString();

#endif
