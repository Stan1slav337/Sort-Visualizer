#include <algorithm>
#include "RadixSort.h"

void RadixSort::Sort() {

    int max = (*max_element(nums.begin(), nums.end(), [](Elem* el1, Elem* el2) {
            return *el1 < *el2;
        }))->getRect().height();

	for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(exp);

}

void RadixSort::countSort(int exp) {

    const size_t LEN = nums.size();

    vector<Elem> out(LEN);
    vector<int> count(10, 0);

    for (int i = 0; i < LEN; ++i) {

        accesVisual({ i });

        count[(nums[i]->getHeight() / exp) % 10]++;

    }

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = LEN - 1; i >= 0; --i) {

        accesVisual({ i });

        out[count[(nums[i]->getHeight() / exp) % 10] - 1] = *nums[i];
        count[(nums[i]->getHeight() / exp) % 10]--;

    }

    for (size_t i = 0; i < LEN; ++i)
        setVisual(i, out[i]);

}