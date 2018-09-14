#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QPixmap>
#include <QDirIterator>
#include <QDebug>
#include <QIcon>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton *button1;
    QPushButton *button2;

    int randomValueTemp;
    int *numberArray;
    int numberOfImages;
    int numberOfUnusingedBox;
    int numberOfBox;
    void gameStart();
    void setButtonImage(int buttonId1, int buttonId2, QString path);
    bool controlImage(QPushButton *b1,QPushButton *b2);
    void checkButton(QPushButton *b1);
    int checkedButton;


signals:
    void Mouse_Pressed();
public slots:
    int numberBox();
    void pressedButton();
    void buttonUpdate();
    void updateGame();
private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
