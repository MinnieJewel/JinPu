#include "tractionisolate.h"
#include "ui_tractionisolate.h"
#include "global.h"
#include <QDebug>

#define BTN_UNSELECTED ("background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("background-color: rgb(0, 0, 250); border-radius: 5px;")

enum buttonId
{
    MP1TCU1 = 0,
    MP1TCU2,
    MP1TCU3,
    MP1TCU4,
    MP2TCU1,
    MP2TCU2,
    MP2TCU3,
    MP2TCU4
};

TractionIsolate::TractionIsolate(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TractionIsolate)
{
    ui->setupUi(this);
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(ui->btn_mp1tcu1, MP1TCU1);
    this->buttonGroup->addButton(ui->btn_mp1tcu2, MP1TCU2);
    this->buttonGroup->addButton(ui->btn_mp1tcu3, MP1TCU3);
    this->buttonGroup->addButton(ui->btn_mp1tcu4, MP1TCU4);
    this->buttonGroup->addButton(ui->btn_mp2tcu1, MP2TCU1);
    this->buttonGroup->addButton(ui->btn_mp2tcu2, MP2TCU2);
    this->buttonGroup->addButton(ui->btn_mp2tcu3, MP2TCU3);
    this->buttonGroup->addButton(ui->btn_mp2tcu4, MP2TCU4);

    for (int buttonId = 0; buttonId < this->buttonGroup->buttons().size(); buttonId ++)
    {
        this->buttonGroup->button(buttonId)->setCheckable(true);
        this->buttonState[buttonId] = false;
    }
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonOnClicked(int)));
}

TractionIsolate::~TractionIsolate()
{
    delete ui;
}

void TractionIsolate::on_btn_back_clicked()
{
    emit this->changePage(uSetParameterPage);
}

void TractionIsolate::buttonOnClicked(int buttonId)
{
    this->buttonState[buttonId] = !this->buttonState[buttonId];
    this->changeButtonStyle(buttonId, this->buttonState[buttonId]);

    switch(buttonId)
    {
    case MP1TCU1:
        this->database->mp1Tcu1Isolate = this->buttonState[MP1TCU1];
        break;

    case MP1TCU2:
        this->database->mp1Tcu2Isolate = this->buttonState[MP1TCU2];
        break;

    case MP1TCU3:
        this->database->mp1Tcu3Isolate = this->buttonState[MP1TCU3];
        break;

    case MP1TCU4:
        this->database->mp1Tcu4Isolate = this->buttonState[MP1TCU4];
        break;

    case MP2TCU1:
        this->database->mp2Tcu1Isolate = this->buttonState[MP2TCU1];
        break;

    case MP2TCU2:
        this->database->mp2Tcu2Isolate = this->buttonState[MP2TCU2];
        break;

    case MP2TCU3:
        this->database->mp2Tcu3Isolate = this->buttonState[MP2TCU3];
        break;

    case MP2TCU4:
        this->database->mp2Tcu4Isolate = this->buttonState[MP2TCU4];
        break;

    default:
        _LOG <<buttonId << " is not in the buttonList.";
        break;
    }
}


void TractionIsolate::changeButtonStyle(int id, bool clicked)
{
    if (clicked)
        this->buttonGroup->button(id)->setStyleSheet(BTN_SELECTED);
    else
        this->buttonGroup->button(id)->setStyleSheet(BTN_UNSELECTED);
}
