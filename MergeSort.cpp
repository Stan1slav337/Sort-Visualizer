#include "MergeSort.h"

void MergeSort::Sort() {

	Divide(0, nums.size() - 1);

}

void MergeSort::Divide(size_t l, size_t r) {

	if (l == r)
		return;

	size_t mid = l + (r - l) / 2;

	Divide(l, mid);
	Divide(mid + 1, r);
	Merge(l, r);

}

void MergeSort::Merge(size_t l, size_t r) {

	size_t mid = l + (r - l) / 2;

	vector<Elem> sorted;

	for (int i = l, j = mid + 1; i <= mid || j <= r;) {

		accesVisual({ i, j });

		if (j > r || (i <= mid && *nums[i] < *nums[j]))
			sorted.push_back(*nums[i++]);
		else
			sorted.push_back(*nums[j++]);

	}

	for (int i = l; i <= r; ++i)
		setVisual(i, sorted[i - l]);
		
}