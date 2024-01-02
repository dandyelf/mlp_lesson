#include "mlp_main_win.h"

#include "ui_mlp_main_win.h"

MlpMainWin::MlpMainWin(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MlpMainWin) {
  ui_->setupUi(this);
  BlinkingButton();
  //  m_label = new QLabel(this);
}

MlpMainWin::~MlpMainWin() { delete ui_; }

void MlpMainWin::BlinkingButton() {
  m_timer_ = new QTimer(this);
  m_timer_->setInterval(500);
  connect(m_timer_, &QTimer::timeout, this, &MlpMainWin::Toggle);
  m_timer_->start();
  button_blink_ = ui_->button1_set_data;
}

void MlpMainWin::Toggle() {
  // Инвертируем состояние кнопки
  //  qDebug() << "Toggle " + QTime::currentTime().toString();
  button_blink_->setChecked(!button_blink_->isChecked());
}

void MlpMainWin::BlinkLogic() {
  m_timer_->start();
  button_blink_->setChecked(true);
  if (!set_data_1_)
    button_blink_ = ui_->button1_set_data;
  else if (!load_data_2_)
    button_blink_ = ui_->button2_load_data;
  else if (!add_tests_3_)
    button_blink_ = ui_->button3_add_tests;
  else if (!load_tests_4_)
    button_blink_ = ui_->button4_load_tests;
  else
    button_blink_ = ui_->button5_start_edu;
}

void MlpMainWin::on_button1_set_data_clicked() {
  set_data_1_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button2_load_data_clicked() {
  load_data_2_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button3_add_tests_clicked() {
  add_tests_3_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button4_load_tests_clicked() {
  load_tests_4_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button5_start_edu_clicked() {
  set_data_1_ = false;
  load_data_2_ = false;
  add_tests_3_ = false;
  load_tests_4_ = false;
  BlinkLogic();
}
