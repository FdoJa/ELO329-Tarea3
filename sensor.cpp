#include "sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(int z, bool close) : zone(z), close(close) {

}

bool Sensor::isClose() const {
    return close;
}

int Sensor::getZone() const {
    return zone;
}

void Sensor::setClose(bool isClose) {
    close = isClose;
    std::cout << "Sensor for zone " << zone << " is " << (close ? "close." : "open.") << std::endl;
}
