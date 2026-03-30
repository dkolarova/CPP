/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:31:53 by diana             #+#    #+#             */
/*   Updated: 2026/03/29 11:23:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//check if the string represents a single char (not figit) ex, "a", "*"
bool ScalarConverter::_isChar(const std::string& str)
{
	return str.length() == 1 && !std::isdigit(str[0]);
}


//check if the string represents a valid integer, uses strtol to safely parse and detect errors
bool ScalarConverter::_isInt(const std::string& str)
{
	char* end;
	errno = 0;

	long value = std::strtol(str.c_str(), &end, 10);
	//if parsing didnt consume the whole string or overflow happened = invalid
	if (*end != '\0' || errno == ERANGE)
		return false;

	//check if value fits in an int
	return (value >= std::numeric_limits<int>::min() &&
			value <= std::numeric_limits<int>::max());
}


//check if the string represent a valid float, must end with 'f'
bool ScalarConverter::_isFloat(const std::string& str)
{
	//Handle pseudo-literals
	if (str == "nanf" || str == "+inf" || str == "-inff")
		return true;
	
	char *end;
	errno = 0;

	std::strtof(str.c_str(), &end);

	//valid float must end with 'f' and nothing after
	return (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE);
}


//check if the string represents a valid double
bool ScalarConverter::_isDouble(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;

	char* end;
	errno = 0;

	std::strtod(str.c_str(), &end);

	//must consume entire string
	return (*end == '\0' && errno != ERANGE);
}


//check if the literal is one of the special values
bool ScalarConverter::_isPseudoLiteral(const std::string& str)
{
	return (str	== "nan"	|| str == "nanf"	||
			str == "+inf"	|| str == "+inff"	||
			str == "-inf"	|| str == "-inff");
}


/* Main conversion */

void ScalarConverter::convert(const std::string& literal)
{
	char	c = 0;
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	//1-detect type + initial conversion
	if (_isChar(literal))
	{
		//direct char conversion
		c = literal[0];

		//convert to other types
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (_isInt(literal))
	{
		char* end;
		i = static_cast<int>(std::strtol(literal.c_str(), &end, 10));

		//convert to other types
		c = (i >= 0 && i <= 127) ? static_cast<char>(i) : 0;
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (_isFloat(literal))
	{
		//handaling psudo-literals
		if (literal == "nanf")
			f = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff")
			f = -std::numeric_limits<float>::infinity();
		else
		{
			char* end;
			f = std::strtof(literal.c_str(), &end);
		}
		//convert to other types
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = (i >= 0 && i <= 127) ? static_cast<char>(i) : 0;
	}
	else
	{
		std::cout << "Invalid literals" << std::endl;
		return ;
	}
	
	//diplaying results
	// ---- CHAR ----
	std::cout << "char: ";
	if (_isPseudoLiteral(literal) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'\n";

	// ---- INT ----
	std::cout << "int: ";
	if (_isPseudoLiteral(literal) ||
		d > std::numeric_limits<int>::max() ||
		d < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
			std::cout << i << "\n";

	// ---- FLOAT ----
	std::cout	<< "float: "
				<< std::fixed << std::setprecision(1)
				<< f << "f\n";

	// ---- DOUBLE ----
	std::cout	<< "double: "
				<< std::fixed << std::setprecision(1)
				<< d << "\n";
}

//FLOW ~~~~~~
/* 
I first detect the type using helper functions (_isChar, _isInt, etc.)
I convert the string to that type using strtol, strtof, or strtod
Then I use static_cast to convert to the other scalar types
Finally, I print each type while handling edge cases like overflow, non-displayable characters, and pseudo-literals
*/