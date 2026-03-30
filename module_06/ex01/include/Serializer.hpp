/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:52:00 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/30 15:53:38 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER
#define SERIALIZER

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif