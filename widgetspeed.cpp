#include "widgetspeed.h"

WidgetSpeed::WidgetSpeed(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetSpeed::slotSpeed(QString speed)
{
    qDebug() << "Speed accepted" << speed;
    AcceptedSpeedInt = speed.toInt();
    AcceptedSpeedQString = speed;
    update();
}

void WidgetSpeed::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint cent = r.center();

    painter.drawRect(painter.viewport());

    QPixmap Distance("Distance_icon.png");
    QPixmap AVG("AVG_icon.png");
    QPixmap Power("Power_icon.png");
    QImage Speed("Speed.bmp");
    painter.drawPixmap(cent, Distance);
    painter.drawPixmap(QPoint(cent.rx(), cent.ry() + 50), AVG);
    painter.drawPixmap(QPoint(cent.rx(), cent.ry() + 100), Power);
    //painter.drawImage(0,0, Speed);
    painter.drawImage(painter.viewport(), Speed);
    //painter.drawImage(0,0, 600, 600, Speed);


    QFont font("Ubuntu", 20, QFont::Bold);
    QFont font2("Ubuntu", 35, QFont::Bold);
    painter.setFont(font);

    QPoint km(18,32);
    QPoint c1(cent.rx()- 30, cent.ry()- 30);
    QPoint c2(cent.rx()- 20, cent.ry()- 30);
    QPoint c3(cent.rx() - 45, cent.ry()- 30);
    painter.setFont(font);
    painter.drawText(km, "км/ч");

    painter.setFont(font2);
    painter.setPen(Qt::red);

    if (AcceptedSpeedInt < 10)
    {
        painter.drawText(c2, AcceptedSpeedQString);
    }
    // else if (num_lb13 < 100)
    // {
    //     painter.drawText(c1, num_lb13string);
    // }
    // else
    // {
    //     painter.drawText(c3, num_lb13string);
    // }

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

    painter.drawEllipse(cent, radiusx, radiusx);

    //render(painter);
}
