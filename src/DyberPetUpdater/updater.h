#ifndef UPDATER_H
#define UPDATER_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class Updater; }
QT_END_NAMESPACE

class Updater : public QMainWindow
{
    Q_OBJECT

public:
    Updater(QWidget *parent = nullptr);
    ~Updater();

private:
    Ui::Updater *ui;
};
#endif // UPDATER_H
