 //
 // A really bad GUI for controlling the boiler.
 //
 // You should edit this to create a better GUI.
 //
 //

#include "gui.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <status.h>

void GUI::createWidgets()  {

    // time display and boiler on/off buttons
    timeDisplay = new QLineEdit("no time yet");

    on  = new QPushButton("on" );
    off = new QPushButton("off");
}

void GUI::arrangeWidgets() {

    // super-simple layout
    QLayout  *layout = new QHBoxLayout();
    setLayout(layout);

    layout -> addWidget(timeDisplay);
    layout -> addWidget( on  );
    layout -> addWidget( off );

}

void GUI::makeConnections() {

    // on and off buttons control the boiler.
    // Alternately, you may chose to control the boiler using boilerOn/Off in timeChanged.
    connect(on ,  SIGNAL ( released() ), status,  SLOT ( boilerOn () ) );
    connect(off,  SIGNAL ( released() ), status,  SLOT ( boilerOff() ) );
}

void GUI::timeChanged(QTime* time) {
    timeDisplay->setText("time: "+time->toString());
}
