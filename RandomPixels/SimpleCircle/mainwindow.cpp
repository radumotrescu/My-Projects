#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <qgraphicsscene.h>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(buttonClick()));
}

void MainWindow::buttonClick()
{
    double radius=ui->doubleSpinBox->value();

    QGraphicsScene* scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    QGraphicsEllipseItem* item5= new QGraphicsEllipseItem(ui->centralWidget->size().width()/2, ui->centralWidget->size().height()/2, radius, radius);
    item5->setBrush(QBrush(Qt::black));
    scene->addItem(item5);
}

MainWindow::~MainWindow()
{
    delete ui;
}
