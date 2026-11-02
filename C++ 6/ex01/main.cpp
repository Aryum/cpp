/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:55:56 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 15:05:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data	data;

	data.name = "Ricardo";
	data.age = 25;
	data.phoneNumber = 123456789;

	uintptr_t raw = Serializer::serialize(&data);
	Data* result = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &data << "\n";
	std::cout << "Deserialized pointer: " << result << "\n";
	std::cout << "Pointers match: " << (&data == result ? "yes" : "no") << "\n";

	std::cout << "Default\n";
	std::cout << YELLOW << "	Name: " << WHITE << data.name << "\n";
	std::cout << BLUE << "	Age: " << WHITE << data.age << "\n";
	std::cout << GREEN << "	PhoneNumber: " << WHITE << data.phoneNumber << "\n";
	
	std::cout << "Result\n";
	std::cout << YELLOW << "	Name: " << WHITE << result->name << "\n";
	std::cout << BLUE << "	Age: " << WHITE << result->age << "\n";
	std::cout << GREEN << "	PhoneNumber: " << WHITE << result->phoneNumber << "\n";

	return 0;
}