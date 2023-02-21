#ifndef DYBERPETCREATOR_H
#define DYBERPETCREATOR_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class DyberPetCreator; }
QT_END_NAMESPACE

class DyberPetCreator : public QMainWindow
{
    Q_OBJECT

public:
    DyberPetCreator(QWidget *parent = nullptr);
    ~DyberPetCreator();

private slots:

private:
    Ui::DyberPetCreator *ui;
};
#endif // DYBERPETCREATOR_H
