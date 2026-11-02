/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:17:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/22 15:27:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define WHITE	"\033[37m"

void	printHeader(const char *msg)
{
	std::cout << BLUE << "-----------" << msg << "-----------\n" << WHITE;
}

void	subjectTest()
{
	printHeader("Subject example");

	MutantStack<int> mstack;
	std::stack<int> control;
	mstack.push(5);
	control.push(5);
	mstack.push(17);
	control.push(17);
	std::cout << "mutant top: " << mstack.top() << "\n";
	mstack.pop();
	std::cout <<  "size after pop: " << mstack.size() << "\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Iterating:" << "\n";
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Copied to std::stack OK" << "\n";
	std::cout << "\n";
}

void	stackComparison()
{
	printHeader("Stack");

	MutantStack<int> mstack;
	std::stack<int> control;
	mstack.push(5);
	control.push(5);
	
	mstack.push(17);
	control.push(17);
	
	std::cout << "mutant top: " << mstack.top() << "\n";
	std::cout << "control top: " << control.top() << "\n";

	mstack.pop();
	control.pop();
	std::cout <<  "mutant size after pop: " << mstack.size() << "\n";
	std::cout <<  "control size after pop: " << mstack.size() << "\n\n";
	
	mstack.push(3);
	control.push(3);

	mstack.push(5);
	control.push(5);

	mstack.push(737);
	control.push(737);

	mstack.push(0);
	control.push(0);

	std::cout << "Stack content\n" ;
	while (!control.empty())
	{
		std::cout << "	Control	" << control.top() << "\n";
		std::cout << "	Mutant	" << mstack.top() << "\n\n";
		control.pop();
		mstack.pop();
	}
	std::cout << "\n";
}
void	listTest()
{
	printHeader("list test");

	MutantStack<int, std::list<int> > mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << "\n";
	mstack.pop();
	std::cout <<  "size after pop: " << mstack.size() << "\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int, std::list<int> >::iterator start = mstack.begin();
	MutantStack<int, std::list<int> >::iterator end = mstack.end();

	++start;
	--start;
	std::cout << "Iterating:" << "\n";
	while (start != end)
	{
		std::cout << *start << "\n";
		++start;
	}
	std::stack<int, std::list<int> > s(mstack);
	std::cout << "Copied to std::stack OK" << "\n";
	std::cout << "\n";
}
void	stackOperationsTest()
{
	printHeader("Stack operations");

	MutantStack<int> mstack;

	std::cout << "empty: " << (mstack.empty() ? "yes" : "no") << "\n";
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	std::cout << "size: " << mstack.size() << "\n";
	std::cout << "top: " << mstack.top() << "\n";
	mstack.pop();
	std::cout << "top after pop: " << mstack.top() << "\n";
	std::cout << "\n";
}

void	copyConstructorTest()
{
	printHeader("Copy constructor");

	MutantStack<int> mstack;

	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	MutantStack<int> copy(mstack);

	MutantStack<int>::iterator it = copy.begin();
	MutantStack<int>::iterator ite = copy.end();

	std::cout << "Iterating copy:" << "\n";
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::cout << "\n";
}

void	assignmentOperatorTest()
{
	printHeader("Assignment operator");

	MutantStack<int> mstack;
	MutantStack<int> other;

	mstack.push(100);
	mstack.push(200);
	other = mstack;

	MutantStack<int>::iterator it = other.begin();
	MutantStack<int>::iterator ite = other.end();

	std::cout << "Iterating assigned:" << "\n";
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::cout << "\n";
}


void	constIteratorTest(void)
{
	printHeader("Const iterator");

	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	const MutantStack<int> constStack(mstack);

	MutantStack<int>::const_iterator it = constStack.begin();
	MutantStack<int>::const_iterator ite = constStack.end();

	std::cout << "Iterating const stack:" << WHITE << "\n";
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
}

int	main(void)
{
	subjectTest();
	stackComparison();
	listTest();
	stackOperationsTest();
	copyConstructorTest();
	assignmentOperatorTest();
	constIteratorTest();

	return 0;
}