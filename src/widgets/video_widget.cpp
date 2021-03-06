#include "video_widget.h"

#include <QTimer>
#include <QTime>
#include <QMouseEvent>

VideoWidget::VideoWidget(QWidget *parent)
    : QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::red);
    setPalette(p);

    setWindowFlags(Qt::FramelessWindowHint);

    setWindowOpacity(0.5);

    setDigitCount(10);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(150,60);
    showColon = true;
}

void VideoWidget::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if(showColon)
    {
        text[2] = ':';
        showColon = false;
    }
    else
    {
        text[2] = ' ';
        showColon = true;
    }
    display(text);
}

void VideoWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton)
    {
        close();
    }
}
void VideoWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}















