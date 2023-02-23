#include "updater.h"
#include "ui_updater.h"

Updater::Updater(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Updater)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

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


void Updater::on_browseResPack_clicked()
{
    resPackSource = QFileDialog::getOpenFileName(this, ("打开资源文件"), "./", tr("ZIP文件(*.zip);; DyberPet资源包(*.dyberpet);; 所有文件(*.*)"));
    ui->resourcePackEdit->setText(resPackSource);
}

void Updater::updateTabs()
{
    ui->appFrame->setCurrentIndex(tabIndex - 1);
    if (tabIndex == 1){
        ui->updaterNavbarContainer->setStyleSheet("#updaterNavbarContainer{ background: #ffdad9; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->updaterNavbarIcon->setStyleSheet("#updaterNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/updater_selected.svg); }");
        ui->updaterNavbarText->setStyleSheet("#updaterNavbarText{ background: transparent; border: 0px solid #fff; color: #2d1516; font-size: 12px; font-weight: bold; }");
    }
    else{
        ui->updaterNavbarContainer->setStyleSheet("#updaterNavbarContainer{ background: transparent; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->updaterNavbarIcon->setStyleSheet("#updaterNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/updater.svg); }");
        ui->updaterNavbarText->setStyleSheet("#updaterNavbarText{ background: transparent;  border: 0px solid #fff; color: #2d1516; font-size: 12px;}");
    }
    if (tabIndex== 2){
        ui->backupNavbarContainer->setStyleSheet("#backupNavbarContainer{ background: #ffdad9; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->backupNavbarIcon->setStyleSheet("#backupNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/backup_selected.svg); }");
        ui->backupNavbarText->setStyleSheet("#backupNavbarText{ background: transparent; border: 0px solid #fff; color: #2d1516; font-size: 12px; font-weight: bold; }");
    }
    else{
        ui->backupNavbarContainer->setStyleSheet("#backupNavbarContainer{ background: transparent; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->backupNavbarIcon->setStyleSheet("#backupNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/backup.svg); }");
        ui->backupNavbarText->setStyleSheet("#backupNavbarText{ background: transparent;  border: 0px solid #fff; color: #2d1516; font-size: 12px;}");
    }
    if (tabIndex== 3){
        ui->settingsNavbarContainer->setStyleSheet("#settingsNavbarContainer{ background: #ffdad9; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->settingsNavbarIcon->setStyleSheet("#settingsNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/settings_selected.svg); }");
        ui->settingsNavbarText->setStyleSheet("#settingsNavbarText{ background: transparent; border: 0px solid #fff; color: #2d1516; font-size: 12px; font-weight: bold; }");
    }
    else{
        ui->settingsNavbarContainer->setStyleSheet("#settingsNavbarContainer{ background: transparent; border: 0px solid #ffdad9; border-radius: 12px; }");
        ui->settingsNavbarIcon->setStyleSheet("#settingsNavbarIcon{ background: transparent; border-image: url(:/icons/resources/icon/settings.svg); }");
        ui->settingsNavbarText->setStyleSheet("#settingsNavbarText{ background: transparent;  border: 0px solid #fff; color: #2d1516; font-size: 12px;}");
    }
}

void Updater::on_updaterNavbarIcon_clicked()
{
    tabIndex = 1;
    updateTabs();
    ui->appTitle->setText("资源包更新");
    setWindowTitle("呆啵宠物 · 资源包更新");
}


void Updater::on_updaterNavbarText_clicked()
{
    tabIndex = 1;
    updateTabs();
    ui->appTitle->setText("资源包更新");
    setWindowTitle("呆啵宠物 · 资源包更新");
}


void Updater::on_backupNavbarIcon_clicked()
{
    tabIndex = 2;
    updateTabs();
    ui->appTitle->setText("数据备份");
    setWindowTitle("呆啵宠物 · 数据备份");
}


void Updater::on_backupNavbarText_clicked()
{
    tabIndex = 2;
    updateTabs();
    ui->appTitle->setText("数据备份");
    setWindowTitle("呆啵宠物 · 数据备份");
}


void Updater::on_settingsNavbarIcon_clicked()
{
    tabIndex = 3;
    updateTabs();
    ui->appTitle->setText("偏好设置");
    setWindowTitle("呆啵宠物 · 更新器偏好设置");
}


void Updater::on_settingsNavbarText_clicked()
{
    tabIndex = 3;
    updateTabs();
    ui->appTitle->setText("偏好设置");
    setWindowTitle("呆啵宠物 · 更新器偏好设置");
}

void Updater::on_closeApp_clicked()
{
    if (disableExit == true){
        errOpreationInProgress *opreationInProg = new errOpreationInProgress;
        opreationInProg->setParent(ui->titleBar);
        opreationInProg->show();
        int dialogX = this->width();
        dialogX = dialogX - 520 -12 -24;
        opreationInProg->move(dialogX, 0);
    }
    else{
        qApp->quit();
    }
}

void Updater::trigMaximize()
{
    if (formIsMaximized == false){
        this->showMaximized();
        formIsMaximized = true;
        ui->windowContainer->setMargin(0);
        ui->shadeContainer->setStyleSheet("#shadeContainer{ border: 2px solid rgb(189,167,165); border-radius: 0px; background: rgb(241,234,235); }");
        ui->menuBarSE->setStyleSheet("#menuBarSE{ background: rgb(241,234,235); border: 1px solid rgb(241,234,235); border-top-left-radius: 0px; border-top-right-radius: 0px; border-bottom-left-radius: 0px; border-bottom-right-radius: 0px; }");
        ui->navBar->setStyleSheet("#navBar{ background: #f5f0f0; border: 1px solid #f5f0f0; border-top-left-radius: 0px; border-top-right-radius: 0px; border-bottom-left-radius: 0px; border-bottom-right-radius: 0px; }");
    }
    else{
        this->showNormal();
        formIsMaximized = false;
        ui->windowContainer->setMargin(12);
        ui->shadeContainer->setStyleSheet("#shadeContainer{ border: 2px solid rgb(189,167,165); border-radius: 10px; background: rgb(241,234,235); }");
        ui->menuBarSE->setStyleSheet("#menuBarSE{ background: rgb(241,234,235); border: 1px solid rgb(241,234,235); border-top-left-radius: 10px; border-top-right-radius: 10px; border-bottom-left-radius: 0px; border-bottom-right-radius: 0px; }");
        ui->navBar->setStyleSheet("#navBar{ background: #f5f0f0; border: 1px solid #f5f0f0; border-top-left-radius: 0px; border-top-right-radius: 0px; border-bottom-left-radius: 10px; border-bottom-right-radius: 10px; }");
    }
}

void Updater::on_maximizeApp_clicked()
{
    trigMaximize();
}


void Updater::on_minimizeApp_clicked()
{
    this->showMinimized();
}

void Updater::mousePressEvent(QMouseEvent *event)
{
    mousePointInit = event->pos();
    if (formIsMaximized == false){
        if (mousePointInit.y() < 100){
            if (mousePointInit.y() > 12){
                windowMovementStart = true;
            }
        }
    }
}

void Updater::mouseMoveEvent(QMouseEvent *event)
{
    if (windowMovementStart == true){
        move(event->globalPos() - mousePointInit);
    }
}

void Updater::mouseReleaseEvent(QMouseEvent *event)
{
    windowMovementStart = false;
}

void Updater::mouseDoubleClickEvent(QMouseEvent *event)
{
    trigMaximize();
}
