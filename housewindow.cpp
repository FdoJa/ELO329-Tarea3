#include "housewindow.h"
#include "ui_housewindow.h"
#include <QDir>

HouseWindow::HouseWindow(QWidget *parent, Central *central) : QMainWindow(parent), ui(new Ui::HouseWindow), central(central)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);

    // Botones:
    btnPerimeter = new QPushButton("P", ui->alarmRegion);
    btnDisarm = new QPushButton("D", ui->alarmRegion);

    btnPerimeter->setGeometry(45, 300, 50, 50);
    btnDisarm->setGeometry(105, 300, 50, 50);

    connect(btnPerimeter, &QPushButton::clicked, this, &HouseWindow::activateSensorClicked);
    connect(btnDisarm, &QPushButton::clicked, this, &HouseWindow::desactivateSensorClicked);

    // Conectar para cambiar alarma según apertura de puertas/ventanas

    // Display:
    Display = new QLabel("Seguridad activada", ui->alarmRegion);
    Display->setGeometry(50, 150, 100, 100);

    // Alarma:
    QString imagePath = QDir::currentPath() + "/alarmQuiet.jpg";
    Alarm = new QLabel(ui->alarmRegion);
    Alarm->setGeometry(50, 50, 100, 100);  // Ajusta las coordenadas y el tamaño según tus necesidades
    Alarm->setScaledContents(true);

    QPixmap pixmap; // Reemplaza ":/ruta/imagen1.jpg" con la ruta correcta de la primera imagen
    if (pixmap.load(imagePath)){
        Alarm->setPixmap(pixmap);
    }

    ui->alarmRegion->setMinimumWidth(200);
}

void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}

void HouseWindow::setCentral(Central *centralPtr)
{
    central = centralPtr;
    connect(central, &Central::labelChanged, this, &HouseWindow::updateAlarm);
}

void HouseWindow::activateSensorClicked()
{
    central->perimeter();
    Display->setText(central->getLabel());

    if (central->getLabel() == "Seguridad activa"){
        QString imagePath = QDir::currentPath() + "/alarmQuiet.jpg";
        QPixmap pixmap(imagePath);
        if (pixmap.load(imagePath)) {
            Alarm->setPixmap(pixmap);
        }
    }
}

void HouseWindow::desactivateSensorClicked()
{
    central->disarm();
    Display->setText(central->getLabel());

    QString imagePath = QDir::currentPath() + "/alarmOff.jpg";
    QPixmap pixmap(imagePath);
    if (pixmap.load(imagePath)) {
        Alarm->setPixmap(pixmap);
    }

}

void HouseWindow::updateAlarm(QString newLabel)
{
    if (newLabel == "Zona 0 abierta." or newLabel == "Zona 1 abierta." or newLabel == "Zonas 0 y 1 abiertas.") {
        QString imagePath = QDir::currentPath() + "/alarmSounding.jpg";
        QPixmap pixmap(imagePath);
        if (pixmap.load(imagePath)) {
            Alarm->setPixmap(pixmap);
        }
    }
}

HouseWindow::~HouseWindow()
{
    delete ui;
    delete btnPerimeter;
    delete btnDisarm;
}

