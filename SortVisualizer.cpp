#include "SortVisualizer.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "HeapSort.h"

SortVisualizer::SortVisualizer(QWidget *parent) : QMainWindow(parent) {

    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);

    algo = new SortAlg(this);

}

void SortVisualizer::paintEvent(QPaintEvent* event) {

    algo->showElems();

}

void SortVisualizer::on_actionRandom_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->RandomShuffle();

}

void SortVisualizer::on_actionDecreasing_order_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->DecreasingOrder();

}

void SortVisualizer::on_actionSequential_order_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->SequentialOrder();

}

void SortVisualizer::on_action50_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->InitializeNums(50);

}

void SortVisualizer::on_action100_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->InitializeNums(100);

}

void SortVisualizer::on_action200_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->InitializeNums(200);

}

void SortVisualizer::on_action500_triggered() {

    setWindowTitle("Sort Visualizer");

    algo->InitializeNums(500);

}

void SortVisualizer::on_actionBubble_Sort_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Bubble Sort");

    auto sortAlgo = static_cast<BubbleSort*>(algo);
    sortAlgo->Sort();

    update();

    setWindowTitle("Bubble Sort - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionInsertion_Sort_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Insertion Sort");

    auto sortAlgo = static_cast<InsertionSort*>(algo);
    sortAlgo->Sort();

    update();

    setWindowTitle("Insertion Sort - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionMerge_Sort_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Merge Sort");

    auto sortAlgo = static_cast<MergeSort*>(algo);
    sortAlgo->Sort();

    update();

    setWindowTitle("Merge Sort - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionQuick_Sort_Left_Pivot_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Quick Sort Left");

    auto sortAlgo = static_cast<QuickSort*>(algo);
    sortAlgo->setRandom(false);
    sortAlgo->Sort();

    update();

    setWindowTitle("Quick Sort Left - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionQuick_Sort_Random_Pivot_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Quick Sort Random");

    auto sortAlgo = static_cast<QuickSort*>(algo);
    sortAlgo->setRandom(true);
    sortAlgo->Sort();

    update();

    setWindowTitle("Quick Sort Random - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionRadix_Sort_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Radix Sort");

    auto sortAlgo = static_cast<RadixSort*>(algo);
    sortAlgo->Sort();

    update();

    setWindowTitle("Radix Sort - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::on_actionHeap_Sort_triggered() {

    menuBar()->setEnabled(false);
    setWindowTitle("Heap Sort");

    auto sortAlgo = static_cast<HeapSort*>(algo);
    sortAlgo->Sort();

    update();

    setWindowTitle("Heap Sort - Finished");
    menuBar()->setEnabled(true);

}

void SortVisualizer::delay() const noexcept {

    QApplication::processEvents();

}