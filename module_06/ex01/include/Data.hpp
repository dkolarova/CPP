/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:26:16 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/30 16:36:59 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	int id;
	std::string name;

	Data();
	Data(int i, const std::string& n);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
};

#endif