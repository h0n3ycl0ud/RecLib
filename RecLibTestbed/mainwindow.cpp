#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox b;
    b.setText("Hello, world!");
    b.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
