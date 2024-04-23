#include "widgetcharge.h"

WidgetCharge::WidgetCharge(QWidget *parent)
    : QWidget{parent}
{
}

void WidgetCharge::slotCharge(QString charge)
{
   count += 1;
   if (count == 100){count = 0;}
   qDebug() << "Charge accepted" << charge;
    // AcceptedChargeInt = charge.toInt();
    // AcceptedChargeQString = charge;
   AcceptedChargeInt = count;
   AcceptedChargeQString = AcceptedChargeQString.number(count);
   update();
}

void WidgetCharge::slotVariant1()
{
    qDebug() << "slotVariant1";
}

void WidgetCharge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center = painter.viewport().center();

    painter.setPen(QPen(Qt::lightGray, 2, Qt::SolidLine));
    painter.drawArc(QRect(25, -229-136, 1250, 1250), -1440-1050, -770);

    painter.setPen(QPen(QColor(15, 89, 201), 15, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(QRect(25, -229-136, 1250, 1250), -1440-1050, -7.7*AcceptedChargeInt);


    painter.setBrush(QBrush(Qt::lightGray));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(65, 517, 30, 10, 5, 5);
    painter.drawRoundedRect(65, 0, 30, 10, 5, 5);

//    painter.drawText(center, AcceptedChargeQString);
    painter.setFont(QFont("Ubuntu", 40, QFont::Medium));
    painter.setPen(QPen(Qt::white));
    painter.drawText(QRect(center.x() - 110, center.y() - 100, 220, 120), Qt::AlignHCenter | Qt::AlignBottom,  AcceptedChargeQString + " %");
    painter.setFont(QFont("Ubuntu", 14, QFont::Thin));
    painter.setPen(QPen(Qt::white));
    painter.drawText(QRect(center.x() - 110, center.y() + 20, 220, 120), Qt::AlignHCenter | Qt::AlignTop,  "Заряд батареи");
}
