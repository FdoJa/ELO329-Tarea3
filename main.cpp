#include <iostream>
#include <fstream>
#include <vector>

#include "door.h"
#include "window.h"
#include "central.h"

using namespace std;

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows, junk;

    vector<Door *> doors;
    vector<Window *> windows;
    Central central;

    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }

    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }

    cout << "Argument:" << argv[1] << endl;
    fin >> nDoors;
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;

    for(int i=0; i < nDoors; i++) {
        int zone;
        fin >> junk >> junk >> junk >> zone;

        MagneticSensor * sensor = new MagneticSensor(zone);
        central.addNewSensor(sensor);
        doors.push_back(new Door(sensor));
    }

    for(int i=0; i < nWindows; i++){
        int zone;
        fin >> junk >> junk >> junk >> zone;

        MagneticSensor * sensor = new MagneticSensor(zone);
        central.addNewSensor(sensor);
        windows.push_back(new Window(sensor));
    }

    for (size_t i=0; i<doors.size(); i++) { //size_t : unsigned int for dimensional length
        doors[i]->changeState();
        doors[i]->changeState();
    }

    for (size_t i=0; i<windows.size(); i++) {
        windows[i]->changeState();
        windows[i]->changeState();
    }

    central.checkZones();       // Revisar, debería estar cerrado
    doors[0]->changeState();    // Abrir puerta principal
    central.checkZones();       // Revisar, puerta principal abierta
}
