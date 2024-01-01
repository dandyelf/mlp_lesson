#ifndef MLPMAINWIN_H_
#define MLPMAINWIN_H_

#include <../../controller/s21_controller_perceptron.h>

#include <QMainWindow>
#include <QStyle>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MlpMainWin;
}
QT_END_NAMESPACE

class MlpMainWin : public QMainWindow {
  Q_OBJECT

 public slots:

 public:
  MlpMainWin(QWidget *parent = nullptr);
  ~MlpMainWin();
  void SetControllerObj(s21::ControllerPerceptron *controller_obj) {
    controller_obj_ = controller_obj;
  }
 private slots:
  void toggle();

 private:
  s21::ControllerPerceptron *controller_obj_;
  Ui::MlpMainWin *ui_;
  QTimer *m_timer;
  bool m_isChecked = false;

  //  !!!!!!!
  void BlinkingButton() {
    m_timer = new QTimer(this);
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, this, &MlpMainWin::toggle);
    m_timer->start();
  }

  void updateStyle();
};
#endif  // MLPMAINWIN_H_
