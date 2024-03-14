#ifndef WIDGETSPEED_H
#define WIDGETSPEED_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetSpeed : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSpeed(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int radiusx = 100;
    int AcceptedSpeedInt;
    QString AcceptedSpeedQString;

public slots:
    void slotSpeed(QString speed);

signals:
};

#endif // WIDGETSPEED_H