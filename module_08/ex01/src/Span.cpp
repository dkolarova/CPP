/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:28:44 by diana             #+#    #+#             */
/*   Updated: 2026/04/06 10:13:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");

	_data.push_back(n);
}

int Span::shortestSpan() const
{
	if (_data.size( ))
}