#include "widgettemp.h"

WidgetTemp::WidgetTemp(QWidget *parent)
    : QWidget{parent}
{}

void WidgetTemp::slotTemp(QString temp)
{
    qDebug() << "Temp accepted" << temp;
    AcceptedTempInt = temp.toInt();
    AcceptedTempQString = temp;
    update();
}

void WidgetTemp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint cent = r.center();

    painter.drawRect(painter.viewport());

    painter.setPen(Qt::red);

    painter.drawEllipse(cent, 140, 140);
    painter.drawText(cent, AcceptedTempQString);
}

