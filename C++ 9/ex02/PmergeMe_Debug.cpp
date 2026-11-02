#include "PmergeMe.hpp"

void PmergeMe::Print_Vector(std::string color, std::string name, std::vector<int> vector)
{
	std::cout << color << name << WHITE << " ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << "\n";
}


void PmergeMe::InsertPair_Dbg(std::vector<PairVector> &main, PairVector cur)
{
	size_t bound = main.size();
	for (size_t i = 0; i < main.size(); i++)
	{
		if (main[i].id == 'a' && cur.idx == main[i].idx)
		{
			bound = i;
			break ;
		}
	}
	size_t low = 0;
	size_t high = bound;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (main[mid].nbr > cur.nbr)
		{
			_comparisons++;
			std::cout <<  "	comparing with " << main[mid].id << main[mid].idx << '-' << main[mid].nbr << "\n";
			high = mid;
		}
		else
			low = mid + 1;
	}
	main.insert(main.begin() + low, cur);
	std::cout << "inserting at " << low;
	std::cout << " main (" << main[low].id << main[low].idx << " - " << main[low].nbr << ")\n";
	std::cout << "new main ";
	for (size_t f = 0; f < main.size(); f++)
	{
		if (f == low)
			std::cout << GREEN;
		if (f - 1 == low)
			std::cout << YELLOW;
		for (size_t g = 0; g < main[f].vector.size(); g++)
			std::cout << main[f].vector[g] << " ";
		std::cout << WHITE;
	}
	std::cout << "\n";
}

void PmergeMe::InsertPend_Dbg(std::vector<PairVector> &main, std::vector<PairVector> &pend)
{
	size_t curJacob = 1;
	size_t lastJacob = 1;
	while (1)
	{
		size_t tmp = curJacob;
		curJacob += 2 * lastJacob;
		lastJacob = tmp;

		if (curJacob <= pend.size())
		{
			std::cout << BLUE << "inserting from b" << curJacob << " to b" << lastJacob << "\n" << WHITE;
			for(size_t i = curJacob; i > lastJacob; i--)
			{
				std::cout << "pend (" << pend[i - 2].id << pend[i - 2].idx << "-" << pend[i - 2].nbr << ")";
				InsertPair_Dbg(main, pend[i - 2]);
			}
		}
		else
		{
			std::cout << BLUE << "remaining from b" << lastJacob << " to b" << pend.size() << "\n" << WHITE;
			for(size_t i = pend.size(); i > lastJacob - 1; i--)
			{
				std::cout << "pend (" << pend[i - 1].id << pend[i - 1].idx << "-" << pend[i - 1].nbr << ")";
				InsertPair_Dbg(main, pend[i - 1]);
			}
			break ;
		}
	}
}

void PmergeMe::CreateContainers_Dbg(size_t size, std::vector<PairVector> &main, std::vector<PairVector> &pend, std::vector<int> &odd)
{
	std::cout << "size " << size << "\n";
	int idx = 0;
	while (1)
	{
		std::vector<int> a = GetPair_Vector('a', idx, size);
		std::vector<int> b = GetPair_Vector('b', idx, size);
		std::ostringstream idxStr;
		idxStr << idx;
		if (a.size() == 0 && b.size() == 0)
			break;
		if (b.size() != 0)
			Print_Vector(MAGENTA, "b" + idxStr.str(), GetPair_Vector('b', idx, size));
		if (a.size() != 0)
			Print_Vector(MAGENTA, "a" + idxStr.str(), GetPair_Vector('a', idx, size));
		idx++;
	}

	size_t oddCount = _vector.size() % size;
	if (oddCount != 0)
	{
		for (size_t i = _vector.size() - oddCount; i < _vector.size(); i++ )
			odd.push_back(_vector[i]);
	}
	idx = 0;
	CreatePair_Vector(main, 'b', idx, size );
	while (CreatePair_Vector(main, 'a', idx, size ) && CreatePair_Vector(pend, 'b', idx + 1, size ))
		idx++;
	
	std::cout << YELLOW << "Main " << WHITE;
	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t h = 0; h < main[i].vector.size(); h++)
			std::cout << main[i].vector[h] << " ";
	}
	std::cout << "\n";
	std::cout << GREEN << "Pend " << WHITE;
	for (size_t i = 0; i < pend.size(); i++)
	{
		for (size_t h = 0; h < pend[i].vector.size(); h++)
			std::cout << pend[i].vector[h] << " ";
	}
	std::cout << "\n";

	Print_Vector(RED, "Odd", odd);
}

void PmergeMe::Insert_Dbg(size_t size)
{
	std::vector<PairVector> main;
	std::vector<PairVector> pend;
	std::vector<int> odd;

	CreateContainers_Dbg(size, main, pend, odd);
	InsertPend_Dbg(main, pend);


	int sizeCount = 0;
	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t h = 0; h < main[i].vector.size(); h++)
		{
			std::cout << main[i].vector[h] << " ";
			sizeCount++;
		}
	}
	for (size_t i = 0; i < odd.size(); i++)
	{
			std::cout << odd[i] << " ";
			sizeCount++;
	}
	std::cout << "\n";
	std::cout << RED << "End size " << sizeCount << " ";
	std::cout << "\n";

	_vector.clear();
	for (size_t i = 0; i < main.size(); i++)
		_vector.insert(_vector.end(), main[i].vector.begin(), main[i].vector.end());
	_vector.insert(_vector.end(), odd.begin(), odd.end());
}

void PmergeMe::SortPair_Dbg(size_t start, size_t size)
{
	if (_vector.size() / size < 2)
		return ;

	size_t a = start + size * 2 - 1;
	size_t b = start + size - 1;
	if (a < _vector.size())
	{
		_comparisons++;
		if (_vector[b] > _vector[a])
		{
			for (int i = start; i + size <= a; i++)
			{
				int tmp = _vector[i];
				_vector[i] = _vector[i + size];
				_vector[i + size] = tmp;
			}
		}
		SortPair_Dbg(a + 1, size);
	}
	else
	{
		SortPair_Dbg(0, size * 2);
		Insert_Dbg(size);
	}
	
}
