#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Trie* t;
    Trie* root;
    explicit MainWindow(Trie* t, Trie* root, QWidget *parent = nullptr);

    //MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void custombuttonClicked(QString num);
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
