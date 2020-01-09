#include "mainwindow.h"

#include <QApplication>
#include <QObject>
#include <fstream>

int main(int argc, char *argv[])
{
    Trie* t = new Trie();
    Trie* root = t->createNode();

    std::ifstream input;
    input.open("dictionary.txt");
    std::string word;
    if(input.is_open()){
        while(getline(input, word)){
            t->insert(word, root);
        }
    }
    input.close();

    QApplication a(argc, argv);
    MainWindow w(t, root);
    w.show();

    /*
            TODO:
            - ADD WORD PRIORITIES!
            - CHANGE GUI



    */


    return a.exec();
}
