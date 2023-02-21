#include "updater.h"
#include "ui_updater.h"

Updater::Updater(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Updater)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect * applicationShadow = new QGraphicsDropShadowEffect;
    applicationShadow->setColor(QColor(189,167,165));
    applicationShadow->setOffset(0,0);
    applicationShadow->setBlurRadius(20);
    ui->shadeContainer->setGraphicsEffect(applicationShadow);

}

Updater::~Updater()
{
    delete ui;
}

