/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:07:28 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/12 15:42:36 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#	define AForm_HPP

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>

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

class AForm
{
	public:
		AForm(void);
		AForm(const AForm& other);
		AForm(std::string name, std::string target, int grade_exec, int grade_sign);
		~AForm();


		AForm& operator=(const AForm& other);

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		std::string getName(void) const;
		int getGrade_Exec(void) const;
		int getGrade_Sign(void) const;
		bool getIsSigned(void) const;
		std::string getTarget(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		
	protected:
		virtual void create(void) const = 0;

	
	private:
		const std::string _name;
		const std::string _target;
		const int _grade_sign;
		const int _grade_execute;
		bool _isSigned;

		void check_grades(void) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &c);

#endif
