#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("background-color:lightblue;");
    setAutoFillBackground( true );

    numberArray=(int*)malloc(sizeof(int)*16);
    gameStart();
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //setCursor(Qt::BlankCursor);



}
void MainWindow::gameStart()
{
    QTimer *timer=new QTimer(this);
    timer->start(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGame()));


    numberOfBox=16;

    numberOfUnusingedBox=16;
    numberOfImages=8;
    randomValueTemp=0;
    int randomValue=0;
    int randomValue2=0;
    checkedButton=0;

    for(int i=0;i<16;i++)
        numberArray[i] = i;

    button1=NULL;
    button2=NULL;

    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        if(it.next().contains(":/images/ImageBox/")){

            QString stringTemp= ":/images/ImageBox/";
            stringTemp.append(it.fileName());

            randomValue= numberBox();
            randomValue2= numberBox();

            setButtonImage(randomValue,randomValue2,stringTemp);


        }
    }

}
void MainWindow::setButtonImage(int buttonId1,int buttonId2 , QString path){

    QPixmap pixma(path);

    QString valueTemp=QString::number(buttonId1);
    QString pushButtonAdress= "pushButton";
    pushButtonAdress.append(valueTemp);

    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setIconSize(pixma.rect().size());
    connect(ui->groupBox->findChild<QPushButton*>(pushButtonAdress),SIGNAL(clicked()),this,SLOT(pressedButton()));
    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setToolTip(path);
    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setToolTipDuration(1);


    valueTemp=QString::number(buttonId2);
    pushButtonAdress= "pushButton";
    pushButtonAdress.append(valueTemp);


    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setIconSize(pixma.rect().size());
    connect(ui->groupBox->findChild<QPushButton*>(pushButtonAdress),SIGNAL(clicked()),this,SLOT(pressedButton()));
    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setToolTip(path.append("_mirror"));
    ui->groupBox->findChild<QPushButton*>(pushButtonAdress)->setToolTipDuration(1);

}


int  MainWindow::numberBox(){


    qsrand(QDateTime::currentMSecsSinceEpoch()/1000);
    int tmp=qrand() % numberOfUnusingedBox+1;
    int returnValue=numberArray[tmp];
    for(int i=tmp;i<16;i++){
        if(i==15)
            numberArray[i]=0;
        else{
            numberArray[i]=numberArray[i+1];

        }
    }
    numberOfUnusingedBox--;
    return returnValue;
}

void MainWindow::pressedButton(){
    if(button1==NULL){
        button1=(QPushButton*)sender();

        if(button1->toolTip().endsWith("_mirror")){
            QPixmap pixma(button1->toolTip().left(23));
            button1->setIcon(pixma);
        }
        else{

            QPixmap pixma(button1->toolTip());
            button1->setIcon(pixma);
        }

    }
    else if(button2==NULL){

        button2=(QPushButton*)sender();
        if(button2->toolTip().endsWith("_mirror")){
            QPixmap pixma(button2->toolTip().left(23));
            button2->setIcon(pixma);

        }
        else{

            QPixmap pixma(button2->toolTip());
            button2->setIcon(pixma);

        }

        if(!controlImage(button1,button2))
            QTimer::singleShot(300,this,SLOT(buttonUpdate()));

    }

}

bool MainWindow::controlImage(QPushButton *b1, QPushButton *b2)
{
    if(b1->toolTip()==b2->toolTip().left(23)){

        b1->setEnabled(false);
        checkButton(b1);
        b1=NULL;
        button1=NULL;

        b2->setEnabled(false);
        checkButton(b2);
        b2=NULL;
        button2=NULL;
        return true;
    }
    else if(b1->toolTip().left(23)==b2->toolTip()){

        b1->setEnabled(false);
        checkButton(b1);
        b1=NULL;
        button1=NULL;

        b2->setEnabled(false);
        checkButton(b2);
        b2=NULL;
        button2=NULL;

        return true;
    }
    else
        return false;

}

void MainWindow::checkButton(QPushButton *b1)
{
    QColor col = QColor(Qt::green);
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        b1->setStyleSheet(qss);
        checkedButton++;
    }

}

void MainWindow::buttonUpdate(){


    button1->setIcon(QIcon());
    button1=NULL;
    button2->setIcon(QIcon());
    button2=NULL;
    return;

}

void MainWindow::updateGame()
{

    if(checkedButton==numberOfBox){
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"GameDone","Again?",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes){
            QApplication::quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

        }
        if(reply==QMessageBox::No)
            QApplication::quit();
    }
}

MainWindow::~MainWindow()
{

    delete ui;
    delete button1;
    delete numberArray;
    delete button2;

}


void MainWindow::on_pushButton_clicked()
{

}
