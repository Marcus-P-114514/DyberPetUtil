#include "erropreationinprogress.h"
#include "ui_erropreationinprogress.h"

errOpreationInProgress::errOpreationInProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::errOpreationInProgress)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect * applicationShadow = new QGraphicsDropShadowEffect;
    applicationShadow->setColor(QColor(189,167,165));
    applicationShadow->setOffset(0,0);
    applicationShadow->setBlurRadius(20);
    ui->dialogContainer->setGraphicsEffect(applicationShadow);
}

errOpreationInProgress::~errOpreationInProgress()
{
    delete ui;
}

void errOpreationInProgress::on_confirmDialog_clicked()
{
    this->hide();
}

