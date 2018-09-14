#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer dataTimer;
    QColor randomColor();
    int counter;
    float speed;
    int lineWight;
    double *frequenArray;
    void setFonts(QFont font);
    QSharedPointer<QCPAxisTickerTime> timeTicker2;

private slots:

    void realtimeDataSlot();
    void addGraph();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x, qv_y;
};

#endif // MAINWINDOW_H
