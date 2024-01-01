#include "mlp_main_win.h"

#include "ui_mlp_main_win.h"

MlpMainWin::MlpMainWin(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MlpMainWin) {
  ui_->setupUi(this);
  BlinkingButton();
  updateStyle();
}

MlpMainWin::~MlpMainWin() { delete ui_; }

void MlpMainWin::toggle() {
  // Инвертируем состояние кнопки
  qDebug() << "toggle";
  m_isChecked = !m_isChecked;
  updateStyle();
}

void MlpMainWin::updateStyle() {
  // Получаем текущий стиль кнопки
  QStyle* style = this->style();

  // Устанавливаем стиль для разных состояний кнопки
  if (m_isChecked) {
    setStyleSheet("QPushButton { background-color: rgb(140,198,180); }");
  } else {
    setStyleSheet("QPushButton { background-color: rgb(85,199,180); }");
  }

  // Обновляем стиль кнопки
  style->unpolish(this);
  style->polish(this);
}
