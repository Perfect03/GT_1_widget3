#include "area.h"
#include <QTimerEvent>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200)); // устанавливаем размер зоны, квадрата, линии, и изначальный угол поворота
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter); // вызываем методы рисования
    myrect->move(alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если таймер работает
    {
    alpha=alpha+0.2;
    update(); // увеличиваем угол и обновляем внешний вид
    }
    else
    QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // остановить таймер
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
