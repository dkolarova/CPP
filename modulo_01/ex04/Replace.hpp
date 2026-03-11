/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:28:31 by diana             #+#    #+#             */
/*   Updated: 2026/03/07 07:37:26 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replace
{
	private:
		std::string _to_replace;
		std::string _replace_with;

	public:
		Replace(std::string s1, std::string s2);
		void replace_word(std::string& str);
};

#endif
