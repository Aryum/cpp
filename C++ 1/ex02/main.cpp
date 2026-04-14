/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:45:48 by ricsanto          #+#    #+#             */
/*   Updated: 2025/12/29 15:58:08 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string* stringPTR = &var;
	std::string& stringREF = var;

	std::cout << "Var adress: " << &var << "\n";
	std::cout << "Held by PTR: " << stringPTR << "\n";
	std::cout << "Held by REF: " << &stringREF << "\n\n";

	std::cout << "Var value: " << var << "\n";
	std::cout << "PTR value: " << stringPTR << "\n";
	std::cout << "REF value: " << stringREF << "\n";
}