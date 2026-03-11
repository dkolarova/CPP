/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:37:35 by diana             #+#    #+#             */
/*   Updated: 2026/03/05 11:27:55 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// here we are simply storing the info inside the obj

void Contact::setContact(std::string first_name, std::string	last_name,
						std::string	nick_name, std::string	phone_number,
						std::string	darkest_secret)
{
	firstName =		first_name;
	lastName =		last_name;
	nickname =		nick_name;
	phoneNumber =	phone_number;
	darkestSecret =	darkest_secret;
}

std::string	Contact::getFirstName() const
{
	return firstName;
}

std::string	Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickName() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

void	Contact::displayAll() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
