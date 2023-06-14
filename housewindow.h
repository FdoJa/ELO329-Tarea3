#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QPushButton>
#include <QLabel>
#include "central.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HouseWindow; }
QT_END_NAMESPACE

class HouseWindow : public QMainWindow
{
    Q_OBJECT

public:
    HouseWindow(QWidget *parent = nullptr, Central *central = nullptr);
    void addHouseHollow(QGraphicsItemGroup * ); // doors and windows
    ~HouseWindow();
    void setCentral(Central *central);

private slots:
    void activateSensorClicked();
    void desactivateSensorClicked();
    void updateAlarm(QString newLabel);

private:
    Ui::HouseWindow *ui;
    Central *central;
    QGraphicsScene interiorScene;
    QPushButton *btnPerimeter;
    QPushButton *btnDisarm;
    QLabel *Display;
    QLabel *Alarm;
};

#endif // HOUSEWINDOW_H
