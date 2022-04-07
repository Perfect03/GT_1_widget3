#include "win.h"

Win::Win()
{
    setWindowTitle("Заголовок окна"); // заголовок окна
    area = new Area( this );
    btn = new QPushButton("Завершить",this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};
