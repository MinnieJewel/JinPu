#include "panel.h"
#include "ui_panel.h"
#include "global.h"
#include <QPainter>

Panel::Panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel)
{
    ui->setupUi(this);
    this->currentSpeed = 0;
}

Panel::~Panel()
{
    delete ui;
}

void Panel::setCurrentSpeed(double speed)
{
    if (speed > 120)
        speed = 120;
    this->currentSpeed = speed;
    this->update();
}

void Panel::paintEvent(QPaintEvent *)
{
    this->pPainter = new QPainter(this);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(11);
    QRect rect(100, 100, 400, 300);
    this->pPainter->setRenderHint(QPainter::Antialiasing);
    this->pPainter->setFont(font);
    this->pPainter->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    this->pPainter->setPen(QPen(Qt::yellow, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));

    qreal side = qMin( rect.width(), rect.height() );
    //设置原点
    pPainter->translate( rect.x() + rect.width() / 2, rect.y() + rect.height() / 2 );
    //改变刻度，为原来的side/200倍
    pPainter->scale( side / 200.0, side / 200.0 );
    pPainter->save();
    //绘制弧线
    pPainter->drawArc(-100, -100, 200, 200, -30 * 16, 240 * 16);

    QRectF rectKmh( -35, -40, 70, 20 );
    pPainter->setBrush(QBrush(Qt::NoBrush));
    pPainter->drawRect( rectKmh );
    QRectF rectSpeed( -25, 20, 50, 30 );
    pPainter->drawRect( rectSpeed );
    QString str;

    pPainter->setFont( font );
    pPainter->save();
    pPainter->rotate(60);
    for (int i = 0; i < 121; ++i) {
        if(i == 80)
        {
            pPainter->setPen(QPen(Qt::yellow, 1, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
        }
        else
        {
            if (i > 80)
            {
                pPainter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
            }
            else
            {
                pPainter->setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
            }
        }
        //end
        if(i % 5==0){
            pPainter->drawLine(0, 85, 0, 100);
        }
        else
            //if(i % 5 == 0)
        {
            pPainter->drawLine(0, 90, 0, 100);
        } // end if...else

        if (i == (int)this->currentSpeed)
        {
            static const QPointF points[3] = {
                QPointF(0, 90),
                QPointF(5, 0),
                QPointF(-5, 0)
            };
            pPainter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
            pPainter->setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
            pPainter->drawPolygon(points, 3);
        }

        pPainter->rotate(2);
    } // end for
    pPainter->restore();
    pPainter->setFont( QFont("SimHei",  12,QFont::Bold, FALSE ) );
    pPainter->drawText( rectKmh, Qt::AlignCenter, QString("km/h") );
    pPainter->setFont( QFont("SimHei",  12,QFont::Bold, FALSE ) );
    pPainter->setPen(QPen(Qt::yellow, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
    pPainter->drawText( QRectF( -12, -81, 25, 20 ), Qt::AlignCenter, "60" );
    pPainter->drawText( QRectF( 15, -77, 25, 20 ), Qt::AlignCenter, "70" );
    pPainter->drawText( QRectF( -39, -77, 25, 20 ), Qt::AlignCenter, "50" );
    pPainter->drawText( QRectF( 39, -63, 25, 20 ), Qt::AlignCenter, "80" );
    pPainter->drawText( QRectF( -62, -63, 25, 20 ), Qt::AlignCenter, "40" );
    pPainter->drawText( QRectF( 56, -45, 25, 20 ), Qt::AlignCenter, "90" );
    pPainter->drawText( QRectF( -80, -45, 25, 20 ), Qt::AlignCenter, "30" );
    pPainter->drawText( QRectF( 60, -21, 25, 20 ), Qt::AlignVCenter, "100" );
    pPainter->drawText( QRectF(-89, -21, 25, 20 ), Qt::AlignCenter, "20" );
    pPainter->drawText( QRectF( 60, 7, 25, 20 ), Qt::AlignCenter, "110" );
    pPainter->drawText( QRectF( -89, 7, 25, 20 ), Qt::AlignCenter, "10" );
    pPainter->drawText( QRectF( 56, 37, 25, 20 ), Qt::AlignCenter, "120" );
    pPainter->drawText( QRectF( -80, 37, 25, 20 ), Qt::AlignCenter, "0" );

    if(currentSpeed < 80)
    {       
        pPainter->setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
    }
    else
    {
        if(currentSpeed > 80)
        {
            pPainter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
        }
        else
        {
            pPainter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap,Qt::MiterJoin));
        }
    }
    str.append(QString("%1").arg(currentSpeed));
    pPainter->setFont( QFont("SimHei",  12,QFont::Bold, FALSE) );
    pPainter->drawText( rectSpeed, Qt::AlignCenter, str);
    this->pPainter->restore();
    this->pPainter->resetTransform();
}
