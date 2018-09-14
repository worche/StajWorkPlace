#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "lserver.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void gotNewMesssage(QString msg);
    void smbDisconnectedFromServer();
    void smbConnectedToServer();
private slots:


    void on_disconnectButton_clicked();

    void on_testConnectB_clicked();

    void on_connectButton_clicked();

private:

    LServer *server;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
