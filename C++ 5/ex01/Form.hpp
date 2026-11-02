/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:07:28 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/12 15:37:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#	define FORM_HPP

#include "Bureaucrat.hpp"

#ifndef	COLOR
#	define COLOR
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#endif

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const Form& other);
		~Form();

		Form(std::string name, int grade_exec, int grade_sign);

		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		std::string getName(void) const;
		int getGrade_Exec(void) const;
		int getGrade_Sign(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string _name;
		const int _grade_sign;
		const int _grade_execute;
		bool _isSigned;

		void check_grades(void) const;
};

std::ostream &operator<<(std::ostream &out, const Form &c);

#endif

