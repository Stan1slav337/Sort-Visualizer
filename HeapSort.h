#pragma once

#include "SortAlg.h"

class HeapSort : public SortAlg {

	int left(int);
	int right(int);

	void heapify(int, int);

public:

	void Sort();

};