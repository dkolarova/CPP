/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:39:14 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/24 13:35:13 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "===== BASIC TEST =====\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound(); // Cat sound
	j->makeSound(); // Dog sound
	meta->makeSound(); // Animal sound
	delete meta;
	delete j;
	delete i;

	std::cout << "\n===== WRONG TEST =====\n";

	const WrongAnimal* w = new WrongCat();

	std::cout << w->getType() << std::endl;
	w->makeSound(); // ❌ WrongAnimal sound (no virtual)

	delete w;

	std::cout << "\n===== ARRAY TEST =====\n";

	Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int k = 0; k < 4; k++) {
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	for (int k = 0; k < 4; k++) {
		delete animals[k];
	}

	std::cout << "\n===== COPY TEST =====\n";

	Dog originalDog;
	Dog copiedDog = originalDog;

	copiedDog.makeSound();

	std::cout << "\n===== ASSIGNMENT TEST =====\n";

	Cat cat1;
	Cat cat2;

	cat2 = cat1;
	cat2.makeSound();

	std::cout << "\n===== DESTRUCTION TEST =====\n";

	Animal* test = new Dog();
	delete test; // should call Dog then Animal destructor

	return 0;
}

/* int	main(void) {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //wont output the cat sound!
	meta->makeSound();

	delete meta;
	delete i;

	return 0;
}  */