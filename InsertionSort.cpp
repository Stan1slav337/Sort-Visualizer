#include "InsertionSort.h"

void InsertionSort::Sort() {

    for (size_t i = 1; i < nums.size(); ++i) {

        auto cur = *nums[i];
        int j = i - 1;

        while (j >= 0 && *nums[j] >= cur) {

            swapVisual(j + 1, j);
            j--;

        }

    }

}
