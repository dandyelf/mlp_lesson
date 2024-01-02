#ifndef MLPMAINWIN_H_
#define MLPMAINWIN_H_

#include <../../controller/s21_controller_perceptron.h>

#include <QMainWindow>
#include <QStyle>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QTime>

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
  void Toggle();

  void on_button1_set_data_clicked();

  void on_button2_load_data_clicked();

  void on_button3_add_tests_clicked();

  void on_button4_load_tests_clicked();

  void on_button5_start_edu_clicked();

private:
  s21::ControllerPerceptron *controller_obj_{};
  Ui::MlpMainWin *ui_{};
  QTimer *m_timer_{};
  QPushButton * button_blink_{};
  bool set_data_1_{}, load_data_2_{}, add_tests_3_{}, load_tests_4_{};
//  QLabel *m_label;
//  bool m_isChecked = false;

  //  !!!!!!!
  void BlinkingButton();
  void BlinkLogic();
};
#endif  // MLPMAINWIN_H_
