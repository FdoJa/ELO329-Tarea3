#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
}

void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}

void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (closeZones[0] and closeZones[1]){
        cout << "Zonas Cerradas" << endl;
    } else {
        cout << "Alguna zona esta abierta." << endl;
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

Central::~Central(){
    delete timer;
}
