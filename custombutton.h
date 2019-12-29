#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton : public QPushButton
{
Q_OBJECT
public:
    QString number;
    QString letters;
    CustomButton(QString num = "", QString l = "", QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *) override;

private slots:
    void mousePressEvent(QMouseEvent *e) override;

signals:
    void leftClicked();

};

#endif // CUSTOMBUTTON_H
