/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:01:17 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#	define IMATERIASOURCE_HPP

#include <string>
class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void LearnMateria(AMateria* m) = 0;
		virtual AMateria* CreateMateria(std::string const & type) = 0;
};
#endif
