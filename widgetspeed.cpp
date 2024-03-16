#include "widgetspeed.h"

WidgetSpeed::WidgetSpeed(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetSpeed::slotSpeed(QString speed)
{
    count += 1;
    if (count == 120){count = 0;}
    qDebug() << "Speed accepted" << speed;
    // AcceptedSpeedInt = speed.toInt();
    // AcceptedSpeedQString = speed;
    AcceptedSpeedInt = count;
    AcceptedSpeedQString = AcceptedSpeedQString.number(count);
    update();
}

void WidgetSpeed::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint center = r.center();

    painter.drawRect(painter.viewport());

    QFont FontNubmer("Ubuntu", 25, QFont::Thin);

    QFont font2("Ubuntu", 20, QFont::Bold);

    painter.setFont(FontNubmer);
    painter.setPen(QPen(Qt::white));

    QPoint p11(390,380); //120 // 280,280
    QPoint p22(415,170+60);
    QPoint p3(370, 90+30); //
    QPoint p4(245, 40+30);
    QPoint p5(110, 90+30);
    QPoint p6(50, 170+60);
    QPoint p7(70, 280+100); // 0
    QPoint k(245,320);

    painter.drawText(p11, "120");
    painter.drawText(p22, "100");
    painter.drawText(p3, "80");
    painter.drawText(p4, "60");
    painter.drawText(p5, "40");
    painter.drawText(p6, "20");
    painter.drawText(p7, "0");
    painter.drawText(k, "км/ч");


    painter.setFont(QFont("Ubuntu", 55, QFont::Medium));
    painter.setPen(QPen(Qt::white));
    painter.drawText(center, AcceptedSpeedQString);

    QPixmap Distance("Distance_icon.png");
    QPixmap AVG("AVG_icon.png");
    QPixmap Power("Power_icon.png");
    //QImage Speed("Speed.bmp");
    painter.drawPixmap(center, Distance);
    painter.drawPixmap(QPoint(center.rx(), center.ry() + 50), AVG);
    painter.drawPixmap(QPoint(center.rx(), center.ry() + 100), Power);
    //painter.drawImage(painter.viewport(), Speed);

    painter.setPen(QPen(QColor(22, 48, 87), 5, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(QRect(5,5, 515, 515), -480, 2880+960);
    painter.drawArc(QRect(19,19, 485, 485), -480, 2880+960);
    //painter.drawArc(center.rx(),center.ry(), 515, 515, -480, 2880+960);
    //painter.drawArc(painter.viewport(), -480, 2880+960);
    painter.translate(center);

    QPoint p1(radius-20,0);
    QPoint p2(radius-4, 0);
    int i = 10;
    for (int count = 1; count <=36; count++)
    {
        if (count <= 4 || count > 15)
        {
            if (count % 4 == 0)
            {
                painter.setPen(QPen(Qt::lightGray, 7, Qt::SolidLine, Qt::RoundCap));
                painter.drawLine(p1, p2);
                painter.rotate(i);
            }
            else
            {
                painter.rotate(i);
            }
        }
        else
        {
            painter.rotate(i);
        }
    }

    painter.resetTransform();
    painter.translate(center);
    painter.rotate(-210);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));

    if (AcceptedSpeedInt != 0)
    {
        painter.rotate(AcceptedSpeedInt*2);
        QPoint p3(radius - 60,0);
        QPoint p4(radius - 10, 0);
        painter.drawLine(p3,p4);
    }

}
