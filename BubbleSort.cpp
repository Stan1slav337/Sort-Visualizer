#include "BubbleSort.h"

void BubbleSort::Sort() {

    const size_t LEN = nums.size();

    for (size_t i = 0; i < LEN - 1; ++i)
        for (size_t j = i + 1; j < LEN; ++j)
            if (*nums[i] > *nums[j])
                swapVisual(i, j);

}