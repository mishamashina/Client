#include "widgetright.h"

WidgetRight::WidgetRight(QWidget *parent)
    : QWidget{parent}
{}

void WidgetRight::slotRight()
{
    update();
}

void WidgetRight::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center = painter.viewport().center();
    painter.drawRect(painter.viewport());

    QPixmap Distance("Distance_icon.png");
    QPixmap AVG("AVG_icon.png");
    QPixmap Power("Power_icon.png");
    //QImage Speed("Speed.bmp");

    painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 100), Distance);
    painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 10), AVG);
    painter.drawPixmap(QPoint(painter.viewport().x(), center.ry() +80), Power);

    // painter.setPen(QPen(QColor(15, 89, 201), 12, Qt::SolidLine, Qt::RoundCap));

    // painter.drawArc(QRect(10, 10, 260, 260), 1440 , count*57.6);
    // painter.drawText(center, AcceptedChargeQString);
}
