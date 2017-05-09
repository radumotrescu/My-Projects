#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <time.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  struct Color {
    int R, G, B;
    void createColor(int newR, int newG, int newB) {
      R = newR;
      G = newG;
      B = newB;

    }
    QColor getColor() {
      return QColor(R, G, B);
    }
  };
  std::vector<Color> colorList;

 private slots:
  void generateRandomPixels();
};

#endif // MAINWINDOW_H
