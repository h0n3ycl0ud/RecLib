#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Stream<char> test();
    cout << test.GetPtr();


    QMessageBox b;
    b.setText("Hello, world!");
    b.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}
