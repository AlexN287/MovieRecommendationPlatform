#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTInterface.h"

class QTInterface : public QMainWindow
{
    Q_OBJECT

public:
    QTInterface(QWidget *parent = nullptr);
    ~QTInterface();

private:
    Ui::QTInterfaceClass ui;
};
