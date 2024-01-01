#include "mlp_main_win.h"
#include "ui_mlp_main_win.h"

MlpMainWin::MlpMainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MlpMainWin)
{
    ui->setupUi(this);
}

MlpMainWin::~MlpMainWin()
{
    delete ui;
}

