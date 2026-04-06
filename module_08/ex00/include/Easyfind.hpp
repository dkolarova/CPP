/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:58:27 by diana             #+#    #+#             */
/*   Updated: 2026/04/04 16:20:59 by diana            ###   ########.fr       */
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
