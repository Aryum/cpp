/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/11 18:02:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


// =================== (Cons/Des)tructors ===================

Form::Form() :
	_name("Unamed"), 
	_grade_sign(150),
	_grade_execute(150),
	_isSigned(false)
{
	check_grades();
	std::cout << YELLOW << "Default form created\n" << WHITE;
}

Form::Form(const Form& other) :
	_name(other._name), 
	_grade_sign(other._grade_sign),
	_grade_execute(other._grade_execute),
	_isSigned(false)
{
	check_grades();
	std::cout << YELLOW << "Copied form ";
	std::cout << WHITE  << _name << "\n";
}

Form::Form(std::string name, int grade_exec, int grade_sign) :
	_name(name),
	_grade_sign(grade_sign),
	_grade_execute(grade_exec),
	_isSigned(false)
{
	check_grades();
	std::cout << _name;
	std::cout << YELLOW << " form was printed\n" << WHITE;
}

Form::~Form()
{
	std::cout << _name;
	std::cout << YELLOW << " shreded into pieces\n" << WHITE;
}

// =================== Operators ===================

Form& Form::operator=(const Form& other)
{
	if (&other != this)
		std::cout << MAGENTA << "Forms cannot be rewritten\n" << WHITE;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &c)
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

int Form::getGrade_Exec(void) const
{
	return _grade_execute;
}

int Form::getGrade_Sign(void) const
{
	return _grade_sign;
}

std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
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
	std::cout << _name << "\n";
}

// =================== Private ===================

void Form::check_grades(void) const
{
	if (_grade_execute < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	if (_grade_execute > 150 || _grade_sign > 150)
		throw GradeTooLowException();
}

// =================== Exception ===================

const char *Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
};

const char *Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
};