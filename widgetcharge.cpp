#include "widgetcharge.h"

WidgetCharge::WidgetCharge(QWidget *parent)
    : QWidget{parent}
{}

void WidgetCharge::slotCharge(QString charge)
{
    qDebug() << "Charge accepted" << charge;
    AcceptedChargeInt = charge.toInt();
    AcceptedChargeQString = charge;
    update();
}

void WidgetCharge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint cent = r.center();

    painter.drawRect(painter.viewport());

    painter.setPen(Qt::red);

    painter.drawEllipse(cent, 140, 140);
    painter.drawText(cent, AcceptedChargeQString);
}
