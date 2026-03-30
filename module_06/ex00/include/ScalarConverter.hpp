/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:31:42 by diana             #+#    #+#             */
/*   Updated: 2026/03/29 11:14:40 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cerrno>
#include <cctype>
#include <cstdlib> // strtol, strtof, strtod

class ScalarConverter
{
	private:
		// Private constructor & destructor -> not instantiable
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		// Helper type-checking functions
		static bool _isChar(const std::string& str);
		static bool _isInt(const std::string& str);
		static bool _isFloat(const std::string& str);
		static bool _isDouble(const std::string& str);
		static bool _isPseudoLiteral(const std::string& str);

	public:
		// Main conversion function
		static void convert(const std::string& literal);
};

#endif