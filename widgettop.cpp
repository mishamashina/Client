#include "widgettop.h"

WidgetTop::WidgetTop(QWidget *parent)
    : QWidget{parent}
{}

void WidgetTop::slotTop(QString temp)
{
    qDebug() << "Top accepted" << temp;
    // AcceptedTempInt = temp.toInt();
    // AcceptedTempQString = temp;
    AcceptedTempInt = count;
    AcceptedTempQString = AcceptedTempQString.number(AcceptedTempInt);
    update();
}

void WidgetTop::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center = painter.viewport().center();
    painter.drawRect(painter.viewport());

    QPixmap TopBar("Top_bar.png");
    QPixmap Far("Far.png");
    QPixmap RightTurn("Right_turn.png");
    QPixmap LeftTurn("Left_turn.png");

    painter.drawPixmap(QPoint(41,0), TopBar);
    painter.drawPixmap(QPoint(138,20), Far);
    painter.drawPixmap(QPoint(200, 80), LeftTurn);
    painter.drawPixmap(QPoint(400, 80), RightTurn);

    painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawText(319, 39, QTime::currentTime().toString("hh:mm"));
    painter.drawText(500, 39, AcceptedTempQString);
    qDebug() << "cente" << center.rx() << center.ry();
    //painter.drawText(center, QDateTime::fromTime_t(1).toUTC().toString("hh:mm"));
    // painter.drawArc(QRect(10, 10, 260, 260), 1s440 , count*57.6);
    // painter.drawText(center, AcceptedChargeQString);
}