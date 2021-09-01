 //
 // 2811/User Interfaces resit coursework 2021. A simple GUI for a smart thermostat.
 //
 // You may edit this file if you wish to!
 //
 //  _____                     _____            _        _
 // |_   _|                   |  _  |          | |      | |
 //   | | ___  _ __ ___ ______| | | |______ ___| |_ __ _| |_
 //   | |/ _ \| '_ ` _ \______| | | |______/ __| __/ _` | __|
 //   | | (_) | | | | | |     \ \_/ /      \__ \ || (_| | |_
 //   \_/\___/|_| |_| |_|      \___/       |___/\__\__,_|\__|
 //
 // Tom Kelly 8.2021
 //
 //

#include "status.h"
#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <gui.h>

QTextEdit* status;


int main(int argc, char *argv[]) {

    // create the Qt Application
    QApplication app(argc, argv);

    // create the status window
    Status statusWindow;

    // create the boiler GUI window
    GUI gui(&statusWindow);

    // show the windows and set positions
    gui.show();
    statusWindow.show();
    statusWindow.setGeometry(gui.geometry().x(), gui.geometry().y() + gui.geometry().height() + 30,
                             statusWindow.geometry().width(), statusWindow.geometry().height());

    // wait for the app to terminate
    return app.exec();
}
