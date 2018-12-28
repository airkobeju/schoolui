#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnConectador, &QPushButton::clicked,
            this, &MainWindow::connectDb);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDb()
{
    DatabaseManager dbManager = DatabaseManager::instance();

}
