#include "central.h"
#include <iostream>

void Central::addNewSensor(Sensor *ps){
    zones.push_back(ps);
}

void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (closeZones[0] == false or closeZones[1] == false){
        cout << "Alguna zona esta abierta" << endl;
    } else {
        cout << "Zonas Cerradas" << endl;
    }
}


void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (size_t i=0; i < zones.size(); i++){
        if (zones[i]->isClose() == false){
            int zone;
            zone = zones[i]->getZone();
            closeZones[zone] = false;
        }
    }
}



