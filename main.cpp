#include "SortVisualizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    SortVisualizer w;
    w.show();

    return a.exec();

}
