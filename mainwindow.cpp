#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <iostream>
#include "custombutton.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);


    CustomButton* buttons[9] = {
        new CustomButton("1", ""),
        new CustomButton("2", "abc"),
        new CustomButton("3", "def"),
        new CustomButton("4", "ghi"),
        new CustomButton("5", "jkl"),
        new CustomButton("6", "mno"),
        new CustomButton("7", "pqrs"),
        new CustomButton("8", "tuv"),
        new CustomButton("9", "wxyz"),
    };

    int it = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ui->gridLayout->addWidget(buttons[it++], i, j);
        }
    }

    QSignalMapper* signalMapper = new QSignalMapper (this);
    for(CustomButton* b : buttons){
        connect (b, SIGNAL(leftClicked()), signalMapper, SLOT(map()));
        signalMapper -> setMapping (b, b->number);
    }

    connect (signalMapper, SIGNAL(mapped(QString)), this, SLOT(custombuttonClicked(QString))) ;
}

void MainWindow::custombuttonClicked(QString num)
{
    QString data = ui->textEdit->toPlainText();
    ui->textEdit->setText(data + num);
}


MainWindow::~MainWindow()
{
    delete ui;
}
