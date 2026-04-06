/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:17:37 by diana             #+#    #+#             */
/*   Updated: 2026/04/06 18:09:24 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
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