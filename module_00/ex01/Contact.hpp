/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:36:57 by diana             #+#    #+#             */
/*   Updated: 2026/03/05 08:49:25 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP	
#define	CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void setContact(std::string first_name, std::string	last_name,
						std::string	nick_name, std::string	phone_number,
						std::string	darkest_secret);

	std::string	getFirstName()		const;
	std::string	getLastName()		const;
	std::string	getNickName()		const;
	std::string	getPhoneNumber()	const;
	std::string	getDarkestSecret()	const;

	void displayAll()	const;
};

#endif