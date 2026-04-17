/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:22:26 by diana             #+#    #+#             */
/*   Updated: 2026/04/17 12:53:53 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_data;

	public:
		Span();		
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

	void	addNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;
	
	//range:)' 
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (_data.size() >= _maxSize)
				throw std::runtime_error("Span is full");
			_data.push_back(*begin);
			++begin;
		}
	}
};

#endif