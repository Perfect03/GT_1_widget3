#include "win.h"

Win::Win()
{
    setWindowTitle("Заголовок окна"); // заголовок окна
    area = new Area( this );
    btn = new QPushButton("Завершить",this ); // кнопка

    QVBoxLayout *layout = new QVBoxLayout(this); // вертикальный компоновщик, совмещает зону прорисовки и кнопки
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); // сигнал нажатия кнопок
};
