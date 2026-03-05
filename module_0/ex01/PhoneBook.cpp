/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:55:07 by diana             #+#    #+#             */
/*   Updated: 2026/03/05 13:52:24 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>


// constructor of the phonebook class, it runs when the phonebook obj is created eg(in main.cpp)
PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

// fits inside a 10chars column when displaying contacts in SEARCH table, when name has length +10 fits and puts a . after 10chars
std::string PhoneBook::formatColumn(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact()
{
	std::string firs_name, last_name, nick_name, phone_number, darkest_secrect;
	
	std::cout << "First Name: ";
	std::getline(std::cin, firs_name);
	
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);

	std::cout << "Nickname: ";
	std::getline(std::cin, nick_name);

	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secrect);

	if (firs_name.empty() || last_name.empty() || nick_name.empty() || phone_number.empty() || darkest_secrect.empty())
	{
		std::cout << "Error: fields can't be empty:(" << std::endl;
		return ;
	}

	contacts[oldestIndex].setContact(firs_name, last_name, nick_name, phone_number, darkest_secrect);

	oldestIndex = (oldestIndex + 1) % 8;
	if (count < 8)
		count++;
		
}

void PhoneBook::searchContact() const
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty:(" << std::endl;
		return ;
	}

	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getNickName()) << std::endl;
	}

	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index:(" << std::endl;
		return ;
	}

	int index = input[0] - '0';
	if (index < 0 || index >= count)
	{
		std::cout << "Index out of range:(" << std::endl;
		return ;
	}

	contacts[index].displayAll();
}
