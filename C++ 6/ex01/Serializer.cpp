/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:17:08 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 15:04:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// =================== (Cons/Des)tructors ===================

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer::~Serializer() {}
Serializer& Serializer::operator=(const Serializer& other) 
{ 
	(void)other;
	return *this;
}

// =================== Public ===================

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}