#include "custombutton.h"

#include <QMouseEvent>
#include <QPainter>

CustomButton::CustomButton(QString num, QString l, QWidget *parent) : QPushButton(parent){
    number = num;
    letters = l;
}

void CustomButton::paintEvent(QPaintEvent *paint)
{
    QPushButton::paintEvent(paint);
    QPainter painter(this);
    painter.save();

    QFont font=painter.font() ;
    font.setPointSize(18);
    painter.setFont(font);

    painter.drawText(QPoint(18, 28), number);
    font.setPointSize(12);
    painter.setFont(font);
    painter.drawText(QPoint(38, 25), letters);

    painter.restore();
}

void CustomButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        emit leftClicked();
    }

}
