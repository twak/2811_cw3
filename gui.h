//
// A really bad GUI for controlling the boiler.
//
// You should edit this to create a better GUI.
//
//

#ifndef GUI_H
#define GUI_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <status.h>

class GUI : public QWidget {

    Q_OBJECT

    Status *status;

    QLineEdit* timeDisplay;
    QPushButton*  on;
    QPushButton* off;

public:
    GUI(Status *status) : status(status) {

        // register to get time and temperature udpates in timeChanged function below
        connect(status, SIGNAL(update(QTime*) ), this, SLOT (timeChanged(QTime*)) );
        createWidgets();
        arrangeWidgets();
        makeConnections();
        setWindowTitle("Boiler GUI");
    }

private:

    void createWidgets();

    void arrangeWidgets();

    void makeConnections();

private slots:

    void timeChanged(QTime* time);
};

#endif // GUI_H
