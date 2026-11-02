/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/11 18:02:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// =================== (Cons/Des)tructors ===================

AForm::AForm() :
	_name("Unamed"),
	_target("Unknown"),
	_grade_sign(150),
	_grade_execute(150),
	_isSigned(false)
{
	check_grades();
	std::cout << YELLOW << "Default AForm created\n" << WHITE;
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_target(other._target),
	_grade_sign(other._grade_sign),
	_grade_execute(other._grade_execute),
	_isSigned(false)
{
	check_grades();
	std::cout << YELLOW << "Copied AForm ";
	std::cout << WHITE  << _name << "\n";
}

AForm::AForm(std::string name, std::string target, int grade_exec, int grade_sign) :
	_name(name),
	_target(target),
	_grade_sign(grade_sign),
	_grade_execute(grade_exec),
	_isSigned(false)
{
	check_grades();
	std::cout << _name;
	std::cout << YELLOW << " AForm was printed\n" << WHITE;
}

AForm::~AForm()
{
	std::cout << _name;
	std::cout << YELLOW << " shreded into pieces\n" << WHITE;
}

// =================== Operators ===================

AForm& AForm::operator=(const AForm& other)
{
	if (&other != this)
		std::cout << MAGENTA << "Forms cannot be rewritten\n" << WHITE;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &c)
{
	out << c.getName();
	if (c.getIsSigned())
		out << GREEN << " signed" << WHITE;
	else
		out << RED << " not signed" << WHITE;
	out << BLUE << "\n	exec grade " << WHITE << c.getGrade_Exec();
	out << YELLOW << "\n	sign grade " << WHITE << c.getGrade_Sign();
	out << "\n";
	return out;
}

// =================== Public ===================

int AForm::getGrade_Exec(void) const
{
	return _grade_execute;
}

int AForm::getGrade_Sign(void) const
{
	return _grade_sign;
}

std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

std::string AForm::getTarget(void) const
{
	return _target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
	{
		std::cout << _name;
		std::cout << MAGENTA << " is already signed\n" << WHITE;
		return ;
	}
	if (bureaucrat.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << bureaucrat.getName();
	std::cout << GREEN << " signed " << WHITE;
	std::cout << _name << " \n";
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _grade_execute)
		throw Bureaucrat::GradeTooLowException();
	create();
	std::cout << executor.getName() << BLUE << " executed " << WHITE << _name << "\n";
}

// =================== Private ===================

void AForm::check_grades(void) const
{
	if (_grade_execute < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	if (_grade_execute > 150 || _grade_sign > 150)
		throw GradeTooLowException();
}

// =================== Exception ===================

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
};

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
};

const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed";
};
