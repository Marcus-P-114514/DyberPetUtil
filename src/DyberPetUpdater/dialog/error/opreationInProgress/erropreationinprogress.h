#ifndef ERROPREATIONINPROGRESS_H
#define ERROPREATIONINPROGRESS_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class errOpreationInProgress;
}

class errOpreationInProgress : public QWidget
{
    Q_OBJECT

public:
    explicit errOpreationInProgress(QWidget *parent = nullptr);
    ~errOpreationInProgress();

private slots:
    void on_confirmDialog_clicked();

private:
    Ui::errOpreationInProgress *ui;
};

#endif // ERROPREATIONINPROGRESS_H
