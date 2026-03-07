/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:30:58 by diana             #+#    #+#             */
/*   Updated: 2026/03/07 07:48:49 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string s1, std::string s2)
{
	this->_to_replace = s1;
	this->_replace_with = s2;
}

void Replace::replace_word(std::string& str)
{
	if (this->_to_replace == this-> _replace_with)
		return ;
	if (this->_to_replace.length() < 1)
		return ;

	std::size_t pos = 0;

	while (pos!= std::string::npos)
	{
		pos = str.find(this->_to_replace, pos);
		if (pos == std::string::npos)
			break ;
		str.erase(pos, this->_to_replace.length());
		str.insert(pos, this->_replace_with);
		pos += this->_replace_with.length();
	}
}
