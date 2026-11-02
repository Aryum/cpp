#include "PmergeMe.hpp"

// =================== Creation ===================

std::deque<int> PmergeMe::GetPair_Deque(char letter, size_t nbr, size_t size)
{
	std::deque<int> ret = std::deque<int>();
	size_t idx = nbr * size * 2 + size * (letter == 'a');

	if (idx >= _deque.size() || idx + size > _deque.size())
		return ret;
	return std::deque<int>(_deque.begin() + idx, _deque.begin() + idx + size);
}

bool PmergeMe::CreatePair_Deque(std::deque<PairDeque> &toAppend, char letter, size_t nbr, size_t size)
{
	PairDeque entry;
	size_t vctSize;

	entry.id = letter;
	entry.idx = nbr;
	entry.deque = GetPair_Deque(letter, nbr, size);
	vctSize = entry.deque.size();
	if (vctSize == 0)
		return (false);
	entry.nbr = entry.deque.at(vctSize - 1);
	toAppend.push_back(entry);
	return true;
}

void PmergeMe::CreateContainers_Deque(size_t size, std::deque<PairDeque> &main, std::deque<PairDeque> &pend, std::deque<int> &odd)
{
	size_t oddCount = _deque.size() % size;
	if (oddCount != 0)
	{
		for (size_t i = _deque.size() - oddCount; i < _deque.size(); i++ )
			odd.push_back(_deque[i]);
	}
	int idx = 0;
	CreatePair_Deque(main, 'b', idx, size );
	while (CreatePair_Deque(main, 'a', idx, size ) && CreatePair_Deque(pend, 'b', idx + 1, size ))
		idx++;
}

// =================== Insertion ===================

void PmergeMe::InsertPair_Deque(std::deque<PairDeque> &main, PairDeque cur)
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

void PmergeMe::InsertPend_Deque(std::deque<PairDeque> &main, std::deque<PairDeque> &pend)
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
				InsertPair_Deque(main, pend[i - 2]);
		}
		else
		{
			for(size_t i = pend.size(); i > lastJacob - 1; i--)
				InsertPair_Deque(main, pend[i - 1]);
			break ;
		}
	}
}

void PmergeMe::Insert_Deque(size_t size)
{
	std::deque<PairDeque> main;
	std::deque<PairDeque> pend;
	std::deque<int> odd;

	CreateContainers_Deque(size, main, pend, odd);
	InsertPend_Deque(main, pend);
	_deque.clear();
	for (size_t i = 0; i < main.size(); i++)
		_deque.insert(_deque.end(), main[i].deque.begin(), main[i].deque.end());
	_deque.insert(_deque.end(), odd.begin(), odd.end());
}

// =================== Main ===================

void PmergeMe::SortPair_Deque(size_t start, size_t size)
{
	if (_deque.size() / size < 2)
		return ;

	size_t a = start + size * 2 - 1;
	size_t b = start + size - 1;
	if (a < _deque.size())
	{
		if (_deque[b] > _deque[a])
		{
			for (int i = start; i + size <= a; i++)
			{
				int tmp = _deque[i];
				_deque[i] = _deque[i + size];
				_deque[i + size] = tmp;
			}
		}
		SortPair_Deque(a + 1, size);
	}
	else
	{
		SortPair_Deque(0, size * 2);
		Insert_Deque(size);
	}
	
}

void PmergeMe::SortDeque()
{
	timeval start;
	timeval end;
	gettimeofday(&start, 0);
	if (_deque.size() != 1)
		SortPair_Deque(0, 1);
	gettimeofday(&end, 0);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}