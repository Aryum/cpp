/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/25 10:57:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// =================== (Cons/Des)tructors ===================

Bureaucrat::Bureaucrat() :
	_name("Unamed"), _grade(150)
{
	std::cout << YELLOW << "Default Bureaucrat created\n" << WHITE;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name)
{
	updateGrade(other._grade);
	std::cout << YELLOW << "Cloned Bureaucrat ";
	std::cout << WHITE  << _name << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name)
{
	updateGrade(grade);
	std::cout << _name;
	std::cout << YELLOW << " was spawned\n" << WHITE;
}


Bureaucrat::~Bureaucrat()
{
	std::cout << _name;
	std::cout << YELLOW << " ended their service\n" << WHITE;
}

// =================== Operators ===================

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (&other != this)
	{
		updateGrade(other._grade);
		std::cout << _name;
		std::cout << YELLOW << " was copied\n" << WHITE;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
	out << c.getName();
	out << GREEN << " bureaucrat grade " << WHITE;
	out << c.getGrade();
	return out;
}

// =================== Public ===================

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::string Bureaucrat::getName(void) const
{
	return _name;
}
void Bureaucrat::gradeIncrement(void)
{
	updateGrade(_grade - 1);
}

void Bureaucrat::gradeDecrement(void)
{
	updateGrade(_grade + 1);
}
// =================== Private ===================

void	Bureaucrat::updateGrade(int val)
{
	if (val > 150)
		throw GradeTooLowException();
	if (val < 1)
		throw GradeTooHighException();
	_grade = val;
}

// =================== Exception ===================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
};