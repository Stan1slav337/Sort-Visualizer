#include "HeapSort.h"

void HeapSort::Sort() {

    const int LEN = nums.size();

    for (int i = LEN - 1; i >= 0; --i)
        heapify(i, LEN);

    for (int i = LEN - 1; i > 0; --i) {

        swapVisual(0, i);
        heapify(0, i);

    }

}

int HeapSort::left(int idx) {

    return 2 * idx + 1;

}

int HeapSort::right(int idx) {

    return 2 * idx + 2;

}

void HeapSort::heapify(int idx, int n) {

    int next_idx = idx;

    do {

        idx = next_idx;
        next_idx = idx;

        if (left(idx) < n && *nums[left(idx)] > *nums[next_idx])
            next_idx = left(idx);

        if (right(idx) < n && *nums[right(idx)] > *nums[next_idx])
            next_idx = right(idx);

        swapVisual(idx, next_idx);

    } while (next_idx != idx);

}