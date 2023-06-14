#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z) : Sensor(z) {
}

void MagneticSensor::setSensorOpen() {
    setClose(false);
}

void MagneticSensor::setSensorClose() {
    setClose(true);
}
