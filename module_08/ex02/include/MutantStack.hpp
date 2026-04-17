/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:17:37 by diana             #+#    #+#             */
/*   Updated: 2026/04/17 14:14:51 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTSTACK_HPP
#define MUTANSTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(const MutantStack& other) : std::stack<T>(other){}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack(){}
		
	typedef typename std::stack<T>::container_type::iterator iterator;
	
	iterator begin()
	{
		return this->c.begin();
	}
	
	iterator end()
	{
		return this->c.end();
	}	
};

#endif

//c je interní member std::stack, = skutečný kontejner, kde jsou uložená data