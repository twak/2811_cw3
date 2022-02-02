//
// A simple temperature simulator and status readout.
// DO NOT change this file.
//

#ifndef STATUS_H
#define STATUS_H

#include <QApplication>
#include <vector>
#include <QTimer>
#include <QWidget>
#include <QTextEdit>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <QString>
#include <QTime>
#include <cmath>
#include <math.h>

using namespace std;

class Status : public QTextEdit {

Q_OBJECT

private:
    QTimer* mTimer;

    // current time 1 = 10 mins
    int time = 0;

    // is the boiler on?
    bool boiler = false;

    // temperature inside (affected by boiler and outside temp)
    float insideTemp = 20;
    // temperature outside (goes up and down a bit)
    float outsideTemp = 10;

public:
    Status() : QTextEdit() {

        mTimer = new QTimer(NULL);
        mTimer->setInterval(100); // 250ms between updates
        mTimer->start();
        connect( mTimer, SIGNAL (timeout()), SLOT ( increment() ) ); // ...running shuffle method
        setMinimumSize(130,50);
        setEnabled(false); // can't edit.
        setWindowTitle("Simulator Status");
    }

    float getInsideTemperature() {
        return insideTemp;
    }

    float getOutsideTemperature() {
        return outsideTemp;
    }

private slots:
    void increment() {

        stringstream text;

        text << "time: ";

        int hours = (time/6)%24, mins = (time%6) * 10;
        QTime *t = new QTime( hours, mins );
        emit ( update ( t ) );
        text << t->toString().toUtf8().constData();
        delete(t);

        text << "\nboiler: ";
        text << (boiler ? "on" : "off");

        text << "\ntemperature inside: " << insideTemp << "°C";
        text << "\ntemperature outside: " << outsideTemp << "°C";

        setText( text.str().c_str() );

        time ++; // increments by 10 minutes

        // temperature simulator:
        outsideTemp = sin(6.283 * time / (6.*24.)- 3) * 15; // cold at night, warm in day
        outsideTemp += cos(30 * time / (6.*24.)- 3) * 0.5; // additional noise

        insideTemp -= (insideTemp - outsideTemp) * 0.05; // inside temperature chases outside temperature a bit
        float boilerTemp = boiler ? 120 : outsideTemp; // boiler is very hot when on
        insideTemp -= (insideTemp - boilerTemp) * 0.02; // inside temperature chases boiler temperature a bit less
    }

public slots:

    // Turn the boiler on now
    void boilerOn() {
        boiler = true;
    }

   //Turn the boiler off now
    void boilerOff() {
        boiler = false;
    }

signals:

    // A signal that fires when the simulator updates
    void update(QTime* time);
};

#endif // STATUS_H
