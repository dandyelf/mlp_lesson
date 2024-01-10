#include "s21_tablet.h"
#include "ui_s21_tablet.h"

Tablet::Tablet(QWidget *parent, QImage *img) :
    QDialog(parent),
    ui(new Ui::Tablet)
{
    img_ = img;
    ui->setupUi(this);
}

Tablet::~Tablet()
{
    if(img_ != nullptr) *img_ = ui->graphicsView->GetImage();
    delete ui;
}

void Tablet::on_pushButton_clicked()
{
    ui->graphicsView->Reset();
}

