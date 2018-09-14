#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QLinearGradient>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLinearGradient gradient(-400,-400,400,400);

    
    counter=0;
        speed=1;
        lineWight=3;
    connect(ui->addGrandBt,SIGNAL(clicked()),this,SLOT(addGraph()));

    frequenArray=(double*)malloc(250*sizeof(double));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setCursor(Qt::BlankCursor);


    QFontDatabase::addApplicationFont(":/fontss/Vera.ttf");
    QFont font =QFont("Vera",10,3);
    setFonts(font);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    ui->plot->xAxis->setTicker(timeTicker);
    ui->plot->axisRect()->setupFullAxesBox();
    ui->plot->yAxis->setRange(-1.2, 1.2);

    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QColor MainWindow::randomColor()
{
    QString backgroundColor;
    int R=0,G=0,B=0;
    qsrand(QDateTime::currentMSecsSinceEpoch()/100);
    R=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/1200);
    G=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/500);
    B=qrand()%255;

    return QColor(R,G,B);

}

void MainWindow::setFonts(QFont font)
{
    ui->addGrandBt->setFont(font);
    ui->pushButton_2->setFont(font);
    ui->pushButton->setFont(font);
    ui->statusBar->setFont(font);
    font=QFont("Vera",5,3);
    ui->plot->setFont(font);
    font=QFont("Vera",25,3);
    ui->grandLabel->setFont(font);

}


void MainWindow::realtimeDataSlot()
{
    static QTime time(QTime::currentTime());
    qsrand(QDateTime::currentMSecsSinceEpoch()/100);
    double key = time.elapsed()/(1000/speed);

     double lastPointKey = 0;

    if (key-lastPointKey > 0.002)
    {
      // add data to lines:
      for(int i=0;i<counter;i++)
         {
          ui->plot->graph(i)->addData(key, qSin(key+i)+qSin((key*i)*frequenArray[i]));

      // rescale value (vertical) axis to fit the current data:
      ui->plot->graph(i)->rescaleValueAxis(true);

      }

      //lastPointKey = key;
    }
    ui->plot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->plot->replot(QCustomPlot::rpQueuedReplot);

}

void MainWindow::addGraph()
{

    ui->plot->addGraph();
    ui->plot->graph(counter)->setPen(QPen(randomColor(),2));
    qsrand(QDateTime::currentMSecsSinceEpoch()/100);
    frequenArray[counter]=(qrand()/(double)RAND_MAX*1);
    counter++;
    ui->grandLabel->setText(QString::number(counter));

}

void MainWindow::on_pushButton_clicked()
{
    ui->plot->setBackground(QBrush(randomColor()));
    ui->plot->replot();
}

void MainWindow::on_pushButton_2_clicked()
{

    QString backgroundColor;
    int R=0,G=0,B=0;
    qsrand(QDateTime::currentMSecsSinceEpoch()/100);
    R=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/1200);
    G=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/500);
    B=qrand()%255;

    backgroundColor="background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(";
    backgroundColor.append(QString::number(R));
    backgroundColor.append(",");
    backgroundColor.append(QString::number(G));
    backgroundColor.append(",");
    backgroundColor.append(QString::number(B));
    backgroundColor.append(",255), stop:1 rgba(");

    qsrand(QDateTime::currentMSecsSinceEpoch()/10);
    R=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/120);
    G=qrand()%255;
    qsrand(QDateTime::currentMSecsSinceEpoch()/50);
    B=qrand()%255;

    backgroundColor.append(QString::number(R));
    backgroundColor.append(",");
    backgroundColor.append(QString::number(G));
    backgroundColor.append(",");
    backgroundColor.append(QString::number(B));
    backgroundColor.append(",255));");
    setStyleSheet(backgroundColor);

}
