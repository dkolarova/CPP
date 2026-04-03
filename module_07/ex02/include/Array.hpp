/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:00:59 by dkolarov          #+#    #+#             */
/*   Updated: 2026/04/03 12:09:53 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

//to allow array wirk with any type (int, string, float):)
template <typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
	
	T& operator[](unsigned int index); // to acces elements with []
	const T& operator[](unsigned int index) const; // version for const objcs
	unsigned int size() const;
	
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#include "Array.tpp"

#endif