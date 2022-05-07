#include "QuickSort.h"

void QuickSort::setRandom(bool ok) noexcept {

	random = ok;

}

void QuickSort::Sort() {

	Quick(0, nums.size() - 1);

}

void QuickSort::Quick(size_t l, size_t r) {

	if (l >= r)
		return;

	size_t m = Partition(l, r);
	
	if(m != 0) Quick(l, m - 1);
			   Quick(m + 1, r);

}

void QuickSort::RandomPartition(size_t l, size_t r) {

	size_t randomPivot = getRandom(l, r);

	swapVisual(randomPivot, l);

}

size_t QuickSort::Partition(size_t l, size_t r) {

	if(random)
		RandomPartition(l, r);

	size_t pivot = l;
	Elem cur = *nums[l];

	for(size_t i = l + 1; i <= r; ++i)
		if (*nums[i] <= cur) {

			pivot++;
			swapVisual(pivot, i);

		}

	swapVisual(pivot, l);

	return pivot;

}
