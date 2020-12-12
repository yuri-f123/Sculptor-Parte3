#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visual.h"
#include "sculptor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionputVoxel, SIGNAL(triggered()), ui->widget, SLOT(fig0()));
    connect(ui->actioncutVoxel, SIGNAL(triggered()), ui->widget, SLOT(fig1()));
    connect(ui->actionputBox, SIGNAL(triggered()), ui->widget, SLOT(fig2()));
    connect(ui->actioncutBox, SIGNAL(triggered()), ui->widget, SLOT(fig3()));
    connect(ui->actionputSphere, SIGNAL(triggered()), ui->widget, SLOT(fig4()));
    connect(ui->actioncutSphere, SIGNAL(triggered()), ui->widget, SLOT(fig5()));
    connect(ui->actionputEllipsoid, SIGNAL(triggered()), ui->widget, SLOT(fig6()));
    connect(ui->actioncutEllipsoid, SIGNAL(triggered()), ui->widget, SLOT(fig7()));
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::salvar(){
    //ui->widget->salvarDesenho((char*)"C:/Users/Positivo/Downloads/qt/desenhoParte3.off");
    ui->widget->salvarDesenho((char*)"desenhoParte3.off");
}

