#include "dyberpetcreator.h"
#include "ui_dyberpetcreator.h"

DyberPetCreator::DyberPetCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DyberPetCreator)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect * applicationShadow = new QGraphicsDropShadowEffect;
    applicationShadow->setColor(QColor(189,167,165));
    applicationShadow->setOffset(0,0);
    applicationShadow->setBlurRadius(20);
    ui->shadowFrame->setGraphicsEffect(applicationShadow);

    ui->label->setParent(ui->graphicsWidthEdit);
    ui->label->move(12,-6);
}

DyberPetCreator::~DyberPetCreator()
{
    delete ui;
}

