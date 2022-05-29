#pragma once

#include <vector>
#include "SortVisualizer.h"
#include "SortElem.h"

using std::vector;

class SortAlg {

private:

	void DeInitializeNums();

	void swapElems(size_t, size_t);

protected:

	class SortVisualizer* visual;
	vector<Elem*> nums;
	
	void swapVisual(size_t, size_t);
	void setVisual(size_t, const Elem&);
	void accesVisual(vector<int>);

	size_t getRandom(size_t, size_t);

public:

	SortAlg();
	SortAlg(SortVisualizer*);
	~SortAlg();

	void InitializeNums(const size_t);

	void showElems();

	void RandomShuffle();
	void DecreasingOrder();
	void SequentialOrder();
	void AlmostShuffle();

};
