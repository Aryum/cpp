/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:59:21 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/22 23:58:19 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <exception>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#define MAXCOUNT 10000

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"


struct PairVector
{
	size_t idx;
	char id;
	int nbr;
	std::vector<int> vector;
};

struct PairDeque
{
	size_t idx;
	char id;
	int nbr;
	std::deque<int> deque;
};


class PmergeMe
{
	public:
		static void Sort(int agrc, char **argv, bool debug);
		
		class InvalidNumberException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class TooManyNumbersException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NoArgsException : public std::exception
		{
			virtual const char *what() const throw();
		};
	

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &other);


		static void Print_Vector(std::string color, std::string name, std::vector<int> vector);
		static void InsertPair_Dbg(std::vector<PairVector> &main, PairVector cur);
		static void InsertPend_Dbg(std::vector<PairVector> &main, std::vector<PairVector> &pend);
		static void CreateContainers_Dbg(size_t size, std::vector<PairVector> &main, std::vector<PairVector> &pend, std::vector<int> &odd);
		static void Insert_Dbg(size_t size);
		static void SortPair_Dbg(size_t start, size_t size);
		

		static std::vector<int> GetPair_Vector(char letter, size_t nbr, size_t size);
		static bool CreatePair_Vector(std::vector<PairVector> &toAppend, char letter, size_t nbr, size_t size);
		static void CreateContainers_Vector(size_t size, std::vector<PairVector> &main, std::vector<PairVector> &pend, std::vector<int> &odd);
		static void InsertPair_Vector(std::vector<PairVector> &main, PairVector cur);
		static void InsertPend_Vector(std::vector<PairVector> &main, std::vector<PairVector> &pend);
		static void Insert_Vector(size_t size);
		static void SortPair_Vector(size_t start, size_t size);
		static void SortVector();


		static std::deque<int> GetPair_Deque(char letter, size_t nbr, size_t size);
		static bool CreatePair_Deque(std::deque<PairDeque> &toAppend, char letter, size_t nbr, size_t size);
		static void CreateContainers_Deque(size_t size, std::deque<PairDeque> &main, std::deque<PairDeque> &pend, std::deque<int> &odd);
		static void InsertPair_Deque(std::deque<PairDeque> &main, PairDeque cur);
		static void InsertPend_Deque(std::deque<PairDeque> &main, std::deque<PairDeque> &pend);
		static void Insert_Deque(size_t size);
		static void SortPair_Deque(size_t start, size_t size);
		static void SortDeque();


		static std::vector<int> _vector;
		static double _vectorTime;
		static std::deque<int> _deque;
		static double _dequeTime;
		static int _comparisons;

};
#endif