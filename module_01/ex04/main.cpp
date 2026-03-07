/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:33:46 by diana             #+#    #+#             */
/*   Updated: 2026/03/07 07:47:12 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr <<"Use: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string inFileName = argv[1];
	std::string outFileName = inFileName + ".replace";
	 
	
	if (inFileName.empty())
	{
		std::cerr << "Error: s1 can't be empty :(" << std::endl;
		return 1;
	}
	
	std::ifstream inFile(inFileName.c_str());
	if (!inFile)
	{
		std::cerr << "Error: can't open file :(" << std::endl;
		return 1;
	}

	std::ofstream outFile((inFileName + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error can't create output file :(" << std::endl;
		return 1;
	}
	
	Replace replace(argv[2], argv[3]);
	std::string line;

	while (std::getline(inFile, line))
	{
		replace.replace_word(line);
		outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();
	
	return 0;
}