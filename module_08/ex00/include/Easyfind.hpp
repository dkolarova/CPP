/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:58:27 by diana             #+#    #+#             */
/*   Updated: 2026/04/06 10:21:05 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found");

	return it;
}

#endif


/* 

create a function that searches for an integer inside any container and:

returns an iterator if found
throws an exception if not found

*/