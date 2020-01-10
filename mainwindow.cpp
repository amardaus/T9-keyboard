#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <iostream>
#include "custombutton.h"
#include <fstream>

MainWindow::MainWindow(Trie* t, Trie* root, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->t = t;
    this->root = root;
    this->word = "";

    ui->setupUi(this);
    ui->wordsEdit->setReadOnly(true);


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
    word += num;
    searchWords();
}

void MainWindow::searchWords(){
    QString data = word;
    std::vector<std::string> words = t->search(data.toStdString(), root);

    QString p_word;
    if(!words.empty()){
        p_word = QString::fromStdString(words.at(0));
    }
    else{
        p_word = ui->wordsEdit->toPlainText() + word.right(1);
    }
    ui->wordsEdit->setText(p_word);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteBtn_clicked()
{
    if(word.length() >= 0){
        word.chop(1);
        searchWords();
    }
}

void MainWindow::on_nextBtn_clicked()
{
    QString data = word;
    std::vector<std::string> words = t->search(data.toStdString(), root);

    if(words.size() > 0){
        wordIndex++;
        wordIndex %= words.size();

        QString p_word;
        if(!words.empty()){
            p_word = QString::fromStdString(words.at(wordIndex));
        }
        else{
            p_word = ui->wordsEdit->toPlainText();
        }
        ui->wordsEdit->setText(p_word);
    }
}

void MainWindow::on_spaceButton_clicked()
{
    ui->finalText->setText(ui->finalText->toPlainText() + " " + ui->wordsEdit->toPlainText());
    ui->wordsEdit->setText("");
    word = "";
}
