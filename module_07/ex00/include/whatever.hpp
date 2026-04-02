/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:06:44 by dkolarov          #+#    #+#             */
/*   Updated: 2026/04/01 13:32:51 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const min(T const &a, T const &b)
{
	return (b < a) ? b : a;
}

template <typename T>
T const max(T const &a, T const &b)
{
	return (a < b) ? b : a;
}

#endif


/* 
min(a, b) → if b < a → return b; else → return a
If a == b, b < a is false → returns b → second argument 
max(a, b) → if a < b → return b; else → return a
If a == b, a < b is false → returns b → second argument 
*/