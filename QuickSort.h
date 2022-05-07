#pragma once

#include "SortAlg.h"

class QuickSort: public SortAlg {

	bool random;

	void Quick(size_t, size_t);
	size_t Partition(size_t, size_t);
	void RandomPartition(size_t, size_t);

public:

	void Sort();
	
	void setRandom(bool) noexcept;

};

