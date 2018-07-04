#include "timesetpage.h"
#include "ui_timesetpage.h"
#include <QDateTime>
#include <QTimer>
#include "global.h"
#include <QDebug>
#include <QButtonGroup>


#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 0px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 0px;")

TimeSetPage::TimeSetPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TimeSetPage)
{
    ui->setupUi(this);
    _LOG << "TimeSetPage constructor";
    pushButtonGroup = new QButtonGroup(this);
    pushButtonGroup->setExclusive(true);
    pushButtonGroup->addButton(ui->btn_year, 0);
    pushButtonGroup->addButton(ui->btn_month, 1);
    pushButtonGroup->addButton(ui->btn_day, 2);
    pushButtonGroup->addButton(ui->btn_hour, 3);
    pushButtonGroup->addButton(ui->btn_minute, 4);
    pushButtonGroup->addButton(ui->btn_second, 5);
    connect(pushButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(setSelectedButton(int)));
    ui->btn_year->setChecked(true);
    //record current buttonGroup's id;
    this->counter = 0;

    this->setSelectedButton(counter);
    QPushButton *buttons[] = {
                                ui->btn_0,
                                ui->btn_1,
                                ui->btn_2,
                                ui->btn_3,
                                ui->btn_4,
                                ui->btn_5,
                                ui->btn_6,
                                ui->btn_7,
                                ui->btn_8,
                                ui->btn_9,
                                ui->btn_Clear,
                                ui->btn_confirm,
                                ui->btn_back
    };

       for(unsigned int i = 0; i < (sizeof buttons / sizeof (QPushButton *)); i++)
    {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(mykeyPressEvent()));
    }

       this->timer = new QTimer;
       this->timer->stop();
       connect(this->timer, SIGNAL(timeout()), this, SLOT(resetHmiSetTimeCommand()));
       this->counterTimer = new QTimer;
       this->counterTimer->stop();
       connect(this->counterTimer, SIGNAL(timeout()), this, SLOT(setTimeCommand()));

}

TimeSetPage::~TimeSetPage()
{
    delete ui;
}

void TimeSetPage::updatePage()
{
}

void TimeSetPage::showEvent(QShowEvent *)
{
    this->year = QDateTime::currentDateTime().toString("yy").toInt();
    this->month = QDateTime::currentDateTime().toString("MM").toInt();
    this->day = QDateTime::currentDateTime().toString("dd").toInt();
    this->hour = QDateTime::currentDateTime().toString("hh").toInt();
    this->minute = QDateTime::currentDateTime().toString("mm").toInt();
    this->second = QDateTime::currentDateTime().toString("ss").toInt();

    ui->btn_year->setText(QString::number(this->year));
    ui->btn_month->setText(QString::number(this->month));
    ui->btn_day->setText(QString::number(this->day));
    ui->btn_hour->setText(QString::number(this->hour));
    ui->btn_minute->setText(QString::number(this->minute));
    ui->btn_second->setText(QString::number(this->second));

    ui->label_errorInfo->hide();
}


/*
name:setSelectedButton
function:set label's style which want be set.
parameter:
    label--false:set "year","month","day"
    label--true:set "hour","minute","second"
    index:the index of current row
*/
void TimeSetPage::setSelectedButton(int index)
{
    this->counter = index;
    for(int i = 0; i < this->pushButtonGroup->buttons().size(); i++)
    {
        this->pushButtonGroup->button(i)->setStyleSheet(BTN_UNSELECTED);
    }
    if(pushButtonGroup->button(index))
    {
        pushButtonGroup->button(index)->setStyleSheet(BTN_SELECTED);
    }
}

void TimeSetPage::mykeyPressEvent()
{
    if (this->sender() == ui->btn_Clear)
    {
        this->pushButtonGroup->button(this->counter)->setText(QString(""));
    }
    else if (this->sender() == ui->btn_back)
    {
        emit this->changePage(uSetParameterPage);
    }
    else if(this->sender() == ui->btn_confirm)
    {
        this->year = ui->btn_year->text().toInt();
        this->month = ui->btn_month->text().toInt();
        this->day = ui->btn_day->text().toInt();
        this->hour = ui->btn_hour->text().toInt();
        this->minute = ui->btn_minute->text().toInt();
        this->second = ui->btn_second->text().toInt();

        if (QDate::isValid(2000 + this->year, this->month, this->day)
            && QTime::isValid(this->hour, this->minute, this->second))
        {
            ui->btn_confirm->setEnabled(false);
            this->database->hmisetDateTime.setDate(QDate(2000 + this->year, this->month, this->day));
            this->database->hmisetDateTime.setTime(QTime(this->hour, this->minute, this->second));
//            qApp->processEvents();

//            QDate date(2000 + this->year, this->month, this->day);
//            QTime time(this->hour, this->minute, this->second);
//            QString dateString = date.toString("yyyy-MM-dd");
//            QString timeString = time.toString("hh:mm:ss");
//            QString command = "date -s \"";

//            dateString.replace(QRegExp("-"), "");
//            timeString.replace(QRegExp("-"), ":");
//            command = command + dateString + " " + timeString + "\"";

//            const char *c = command.toAscii().data();

//            //linux command
//            system(c);

//            // write bios
//            system("hwclock -w");

            qDebug() << __DATE__ << __TIME__ << "a user has set time to " << this->database->hmisetDateTime.toString("yyyy-MM-dd hh:mm:ss");
            ui->label_errorInfo->setText("时间设置中，请等待...");
            ui->label_errorInfo->show();

            this->setHmiSetTimeCommand();
        }
        else
        {
            ui->label_errorInfo->setText("时间格式错误，请重新输入！");
            ui->label_errorInfo->show();
        }
    }
    else
    {
       QString text = this->pushButtonGroup->button(this->counter)->text();
       if(text.length() >= 2)
       {
            text.clear();
       }
       this->pushButtonGroup->button(this->counter)->setText(text.append(((QPushButton *)this->sender())->text()));
    }
}

void TimeSetPage::setHmiSetTimeCommand()
{
    if (this->timer->isActive() == false)
    {
        this->database->TimeSetMode = true;
        this->database->flagChecker = 0xAA;
        this->timer->start(5000);
        this->counterTimer->start(20000);
        ui->btn_confirm->setEnabled(false);
        //ui->btn_back->setEnabled(false);
    }
}

void TimeSetPage::resetHmiSetTimeCommand()
{
    this->database->TimeSetMode = false;
    this->database->flagChecker = 0x55;
    this->timer->stop();
}

void TimeSetPage::setTimeCommand()
{
    ui->btn_confirm->setEnabled(true);
    ui->btn_back->setEnabled(true);

    ui->label_errorInfo->setText(QString("时间设置完成！"));
    ui->label_errorInfo->show();
    this->counterTimer->stop();
}
