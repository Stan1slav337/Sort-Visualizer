#pragma once

#include "SortAlg.h"

class MergeSort: public SortAlg {

private:

	void Divide(size_t, size_t);
	void Merge(size_t, size_t);

public:

	void Sort();

};
