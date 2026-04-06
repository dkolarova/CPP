/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:22:26 by diana             #+#    #+#             */
/*   Updated: 2026/04/04 17:29:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_data;

	public:
		Span(unsigned int N);
		~Span();

	void	addNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;
	
	//Bonus
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		if (_data.size() >= _maxSize)
			throw std::runtime_error("Span is full");
		_data.push_back(*begin);
		++begin;
	}
}

#endif