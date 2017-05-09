#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <qpixmap.h>
#include <qimage.h>
#include <iostream>


MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  std::srand(time(NULL));


  for(int i = 0; i < 100; i++) {
    int R = rand() % 255 + 0;
    int G = rand() % 255 + 0;
    int B = rand() % 255 + 0;
    Color newColor;
    newColor.createColor(R, G, B);

    colorList.push_back(newColor);
  }

  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(generateRandomPixels()));
}

void MainWindow::generateRandomPixels() {
  QImage image(ui->graphicsView->width() - 2, ui->graphicsView->height() - 2, QImage::Format_RGB32);

  for(int i = 0; i < image.width(); i++)
    for(int j = 0; j < image.height(); j++) {
      int randomColorIndex = rand() % 100 + 0;
      Color myColor = colorList[randomColorIndex];
      image.setPixelColor(i, j, QColor::QColor(myColor.getColor()));
    }

  QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
  QGraphicsScene* scene = new QGraphicsScene();

  scene->addItem(item);

  ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
  delete ui;
}
