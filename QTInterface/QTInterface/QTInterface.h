#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTInterface.h"

class QTInterface : public QMainWindow
{
    Q_OBJECT

public:
    QTInterface(QWidget* parent = nullptr);
    ~QTInterface();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signUp_clicked();
    void on_checkBox_male_stateChanged(int arg);
    void on_checkBox_female_stateChanged(int arg);
    void on_pushButton_back_clicked();
    void on_actionSign_Out_3_triggered();
    void on_pushButton_change_username_clicked();
    void on_pushButton_change_password_clicked();
private:
    Ui::QTInterfaceClass ui;
};

