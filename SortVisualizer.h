#pragma once

#include <QMainWindow>
#include <QPainter>
#include "ui_SortVisualizer.h"
#include "SortAlg.h"

constexpr auto MENU_HEIGHT = 25;
constexpr auto WINDOW_WIDTH = 1000;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto DEFAULT_N = 100;
constexpr auto ALMOST_N = 5;
constexpr auto NUM_COLOR = Qt::darkCyan;
constexpr auto ACTIVE_NUM_COLOR = Qt::cyan;

class SortVisualizer : public QMainWindow {

    Q_OBJECT

private slots:

    void on_actionRandom_triggered();
    void on_actionDecreasing_order_triggered();
    void on_actionSequential_order_triggered();
    void on_actionAlmost_sorted_triggered();

    void on_action50_triggered();
    void on_action100_triggered();
    void on_action200_triggered();
    void on_action500_triggered();

    void on_actionBubble_Sort_triggered();
    void on_actionInsertion_Sort_triggered();
    void on_actionMerge_Sort_triggered();
    void on_actionQuick_Sort_Left_Pivot_triggered();
    void on_actionQuick_Sort_Random_Pivot_triggered();
    void on_actionRadix_Sort_triggered();
    void on_actionHeap_Sort_triggered();
    
private:

    Ui::SortVisualizerClass ui;
    class SortAlg* algo;

    virtual void paintEvent(QPaintEvent* event);

public:

    SortVisualizer(QWidget* parent = Q_NULLPTR);

    void delay() const noexcept;

};
