#include "PmergeMe.hpp"


// =================== Creation ===================

std::vector<int> PmergeMe::GetPair_Vector(char letter, size_t nbr, size_t size)
{
	std::vector<int> ret = std::vector<int>();
	size_t idx = nbr * size * 2 + size * (letter == 'a');

	if (idx >= _vector.size() || idx + size > _vector.size())
		return ret;
	return std::vector<int>(_vector.begin() + idx, _vector.begin() + idx + size);
}

bool PmergeMe::CreatePair_Vector(std::vector<PairVector> &toAppend, char letter, size_t nbr, size_t size)
{
	PairVector entry;
	size_t vctSize;

	entry.id = letter;
	entry.idx = nbr;
	entry.vector = GetPair_Vector(letter, nbr, size);
	vctSize = entry.vector.size();
	if (vctSize == 0)
		return (false);
	entry.nbr = entry.vector.at(vctSize - 1);
	toAppend.push_back(entry);
	return true;
}

void PmergeMe::CreateContainers_Vector(size_t size, std::vector<PairVector> &main, std::vector<PairVector> &pend, std::vector<int> &odd)
{
	size_t oddCount = _vector.size() % size;
	if (oddCount != 0)
	{
		for (size_t i = _vector.size() - oddCount; i < _vector.size(); i++ )
			odd.push_back(_vector[i]);
	}
	int idx = 0;
	CreatePair_Vector(main, 'b', idx, size );
	while (CreatePair_Vector(main, 'a', idx, size ) && CreatePair_Vector(pend, 'b', idx + 1, size ))
		idx++;
}

// =================== Insertion ===================



void PmergeMe::InsertPair_Vector(std::vector<PairVector> &main, PairVector cur)
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
			high = mid;
		else
			low = mid + 1;
	}
	main.insert(main.begin() + low, cur);
}

void PmergeMe::InsertPend_Vector(std::vector<PairVector> &main, std::vector<PairVector> &pend)
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
			for(size_t i = curJacob; i > lastJacob; i--)
				InsertPair_Vector(main, pend[i - 2]);
		}
		else
		{
			for(size_t i = pend.size(); i > lastJacob - 1; i--)
				InsertPair_Vector(main, pend[i - 1]);
			break ;
		}
	}
}

void PmergeMe::Insert_Vector(size_t size)
{
	std::vector<PairVector> main;
	std::vector<PairVector> pend;
	std::vector<int> odd;

	CreateContainers_Vector(size, main, pend, odd);
	InsertPend_Vector(main, pend);
	_vector.clear();
	for (size_t i = 0; i < main.size(); i++)
		_vector.insert(_vector.end(), main[i].vector.begin(), main[i].vector.end());
	_vector.insert(_vector.end(), odd.begin(), odd.end());
}

// =================== Main ===================

void PmergeMe::SortPair_Vector(size_t start, size_t size)
{
	if (_vector.size() / size < 2)
		return ;

	size_t a = start + size * 2 - 1;
	size_t b = start + size - 1;
	if (a < _vector.size())
	{
		if (_vector[b] > _vector[a])
		{
			for (int i = start; i + size <= a; i++)
			{
				int tmp = _vector[i];
				_vector[i] = _vector[i + size];
				_vector[i + size] = tmp;
			}
		}
		SortPair_Vector(a + 1, size);
	}
	else
	{
		SortPair_Vector(0, size * 2);
		Insert_Vector(size);
	}
	
}

void PmergeMe::SortVector()
{
	timeval start;
	timeval end;
	gettimeofday(&start, 0);
	if (_vector.size() != 1)
		SortPair_Vector(0, 1);
	gettimeofday(&end, 0);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}