/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:28:44 by diana             #+#    #+#             */
/*   Updated: 2026/04/17 12:31:33 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// otodox

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

Span::~Span(){}

// funcs

void Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");

	_data.push_back(n);
}

int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements");

	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());

	return max - min;
}

int Span::shortestSpan() const
{
	if (_data.size( ) < 2)
		throw std::runtime_error("Not enough elements");

	 // Copy the data so we don't modify original
	std::vector<int> tmp = _data;

	// Sort the copy
	std::sort(tmp.begin(), tmp.end());

	int minSpan = INT_MAX;

	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}

	return minSpan;
}

