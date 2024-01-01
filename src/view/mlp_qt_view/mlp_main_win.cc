#include "mlp_main_win.h"

#include "ui_mlp_main_win.h"

MlpMainWin::MlpMainWin(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MlpMainWin) {
  ui_->setupUi(this);
}

MlpMainWin::~MlpMainWin() { delete ui_; }
