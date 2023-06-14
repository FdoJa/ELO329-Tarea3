#ifndef CENTRAL_H
#define CENTRAL_H

#include <QObject>
#include <QString>
#include <vector>
#include <QTimer>
#include "sensor.h"

using namespace std; //needed by vector<>

class Central : public QObject
{
    Q_OBJECT
public:
    explicit Central(QObject *parent = nullptr);
    void addNewSensor(Sensor * ps);
    QString getLabel();
    ~Central();
public slots:
    void perimeter();
    void disarm();
private slots:
    void checkZones();
private:
    bool closeZones[2];
    void checkCloseZones(bool closeZones[]);
    vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer * timer;
    bool security;
    QString label;
signals:
    void labelChanged(QString newLabel);
};

#endif // CENTRAL_H
