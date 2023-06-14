#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
    security = true;
}

void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}

void Central::checkZones() {
    checkCloseZones(closeZones);

    if (closeZones[0] and closeZones[1]){
        cout << "Zonas Cerradas" << endl;
        label = "Zonas cerradas";

    } else {
        if (!closeZones[0] and !closeZones[1]){
            label = "Zonas 0 y 1 abiertas.";
            cout << "Zonas 0 y 1 abiertas." << endl;
        } else if (!closeZones[0]) {
            label = "Zona 0 abierta.";
            cout << "Zona 0 abierta." << endl;
        } else if (!closeZones[1]) {
            label = "Zona 1 abierta.";
            cout << "Zona 1 abierta." << endl;
        }

        if (security == true){
            emit labelChanged(label);
        }
    }
}

void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;

    for (size_t i=0; i< zones.size(); i++){
        if (zones[i]->isClose() == false){
            int zone;
            zone = zones[i]->getZone();
            closeZones[zone] = false;
        }
    }
}

void Central::perimeter() {
    checkZones();

    if (closeZones[0] and closeZones[1]){
        security = true;
        cout << "Seguridad activada." << endl;
        label = "Seguridad activa";
        timer->start(200);
        return;
    }

    if (!closeZones[0] and !closeZones[1]){
        label = "Zonas 0 y 1 abiertas.";
    } else if (!closeZones[0]) {
        label = "Zona 0 abierta.";
    } else if (!closeZones[1]) {
        label = "Zona 1 abierta.";
    }
}

void Central::disarm(){
    cout << "Seguridad desactivada" << endl;
    label = "Seguridad desactivada";
    security = false;
    timer->stop();
    return;
}

QString Central::getLabel() {
    return label;
}

Central::~Central(){
    delete timer;
}
