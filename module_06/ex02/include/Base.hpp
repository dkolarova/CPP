/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:16:24 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/31 17:04:53 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

/* we actually do need the virtual destructor, because without it you cannot properly release the resources held by a derived class 
when using a pointer to the Base class. In other words: 
Base* b = new Derived(); delete b; is Undefined Behavior without a virtual destructor. */
class Base
{
	public:
	virtual ~Base();
};
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif