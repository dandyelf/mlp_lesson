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
    qDebug() << "1" << img_->size();
    *img_ = ui->graphicsView->GetImage();
    qDebug() << "delete tablet" << img_->size();
    delete ui;
}

void Tablet::on_pushButton_clicked()
{
    ui->graphicsView->Reset();
}
