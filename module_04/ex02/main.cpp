/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:39:14 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/24 14:31:36 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	return 0;
}
/* 
int main() {
	std::cout << "\n===== POLYMORPHISM TEST =====\n";
	Animal* animals[4];  // note: Animal is abstract, can't instantiate

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound(); // calls Dog/Cat sound

	for (int i = 0; i < 4; i++)
		delete animals[i];       // correct destructor order

	std::cout << "\n===== Deep copy test (Dog) =====\n";
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chase mailman");

	Dog dog2 = dog1;  // deep copy
	dog2.getBrain()->setIdea(0, "Sleep");

	std::cout << "Dog1: " << dog1.getBrain()->getIdea(0) 
				<< " | Dog2: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n===== Deep copy test (Cat) =====\n";
	Cat cat1;
	cat1.getBrain()->setIdea(0, "Nap");

	Cat cat2;
	cat2 = cat1;  // deep copy via assignment
	cat2.getBrain()->setIdea(0, "Play");

	std::cout	<< "Cat1: " << cat1.getBrain()->getIdea(0) 
				<< " | Cat2: " << cat2.getBrain()->getIdea(0) << std::endl;

	return 0;
}
 */