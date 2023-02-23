#ifndef UPDATER_H
#define UPDATER_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QFile>
#include <QFileDialog>
#include <QMouseEvent>

#include "dialog/error/opreationInProgress/erropreationinprogress.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Updater; }
QT_END_NAMESPACE

class Updater : public QMainWindow
{
    Q_OBJECT

public:
    Updater(QWidget *parent = nullptr);
    ~Updater();

private slots:
    void updateTabs();

    void trigMaximize();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);

    void on_browseResPack_clicked();

    void on_updaterNavbarIcon_clicked();

    void on_updaterNavbarText_clicked();

    void on_backupNavbarIcon_clicked();

    void on_backupNavbarText_clicked();

    void on_settingsNavbarIcon_clicked();

    void on_settingsNavbarText_clicked();

    void on_closeApp_clicked();

    void on_maximizeApp_clicked();

    void on_minimizeApp_clicked();

private:
    Ui::Updater *ui;
    bool disableExit = false;
    bool formIsMaximized = false;
    bool windowMovementStart = false;
    QPoint mousePointInit;
    QString resPackSource;
    int tabIndex = 1;
};
#endif // UPDATER_H
