#include <chrono>
#include <random> 
#include "SortAlg.h"

SortAlg::SortAlg() {

    visual = nullptr;

}

SortAlg::SortAlg(SortVisualizer *visual) {

    this->visual = visual;

    InitializeNums(DEFAULT_N);

}

SortAlg::~SortAlg() {

    delete visual;

    DeInitializeNums();

}

void SortAlg::showElems() {

    const size_t LEN = nums.size();

    QPainter painter(visual);
    QPen pen;

    for (size_t i = 0; i < LEN; ++i) {

        pen.setColor(nums[i]->isActive() ? ACTIVE_NUM_COLOR : NUM_COLOR);
        painter.setBrush(nums[i]->isActive() ? ACTIVE_NUM_COLOR : NUM_COLOR);
        painter.setPen(pen);

        painter.drawRect(nums[i]->getRect());

    }

}

void SortAlg::swapElems(size_t i, size_t j) {

    size_t aux = nums[i]->getTop();
    nums[i]->setTop(nums[j]->getTop());
    nums[j]->setTop(aux);

}

void SortAlg::swapVisual(size_t i, size_t j) {

    swapElems(i, j);

    accesVisual({ (int)i, (int)j });

}

void SortAlg::setVisual(size_t pos, const Elem& el) {

    *nums[pos] = el;

    accesVisual({ (int)pos });

}

void SortAlg::accesVisual(vector<int> positions) {

    const size_t LEN = nums.size();

    for (int pos : positions)
        if(pos < LEN)
            nums[pos]->setActive();

    visual->update();
    visual->delay();

    for (int pos : positions)
        if(pos < LEN)
            nums[pos]->setInactive();

}

size_t SortAlg::getRandom(size_t l, size_t r) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rnd = std::default_random_engine(seed);

    return l + rnd() % (r - l + 1);

}

void SortAlg::InitializeNums(const size_t LEN) {

    DeInitializeNums();

    nums.resize(LEN);

    for (int i = 0; i < LEN; ++i)
        nums[i] = new Elem(
            i * WINDOW_WIDTH / LEN,
            WINDOW_HEIGHT + MENU_HEIGHT - (i + 1) * WINDOW_HEIGHT / LEN,
            WINDOW_WIDTH / LEN,
            (i + 1) * WINDOW_HEIGHT / LEN
        );

    visual->update();

}

void SortAlg::DeInitializeNums() {

    const size_t LEN = nums.size();

    for (size_t i = 0; i < LEN; ++i)
        delete nums[i];

}

void SortAlg::RandomShuffle() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rnd = std::default_random_engine(seed);

    const size_t LEN = nums.size();

    for (size_t i = 0; i < LEN - 1; ++i)
        swapElems(i, i + rnd() % (LEN - i));

    visual->update();

}

void SortAlg::DecreasingOrder() {

    const size_t LEN = nums.size();

    for (size_t i = 0; i < LEN; ++i)
        nums[i] = new Elem(
            i * WINDOW_WIDTH / LEN,
            WINDOW_HEIGHT + MENU_HEIGHT - (LEN - i) * WINDOW_HEIGHT / LEN,
            WINDOW_WIDTH / LEN,
            (LEN - i) * WINDOW_HEIGHT / LEN
        );

    visual->update();

}

void SortAlg::SequentialOrder() {

    const size_t LEN = nums.size();

    for (int i = 0; i < LEN; i += 2)
        nums[i] = new Elem(
            i * WINDOW_WIDTH / LEN,
            WINDOW_HEIGHT + MENU_HEIGHT - (i + 1) * WINDOW_HEIGHT / LEN,
            WINDOW_WIDTH / LEN,
            (i + 1) * WINDOW_HEIGHT / LEN
        );

    for (size_t i = 1; i < LEN; i += 2)
        nums[i] = new Elem(
            i * WINDOW_WIDTH / LEN,
            WINDOW_HEIGHT + MENU_HEIGHT - (LEN - i + 1) * WINDOW_HEIGHT / LEN,
            WINDOW_WIDTH / LEN,
            (LEN - i + 1) * WINDOW_HEIGHT / LEN
        );

    visual->update();

}
