#ifndef MLPMAINWIN_H_
#define MLPMAINWIN_H_

#include <../../controller/s21_controller_perceptron.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MlpMainWin;
}
QT_END_NAMESPACE

class MlpMainWin : public QMainWindow {
  Q_OBJECT

 public:
  MlpMainWin(QWidget *parent = nullptr);
  ~MlpMainWin();
  void SetControllerObj(s21::ControllerPerceptron *controller_obj) {
    controller_obj_ = controller_obj;
  }

 private:
  s21::ControllerPerceptron *controller_obj_;
  Ui::MlpMainWin *ui_;
};
#endif  // MLPMAINWIN_H_
