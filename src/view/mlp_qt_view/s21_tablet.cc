#include "s21_tablet.h"
#include "ui_s21_tablet.h"

Tablet::Tablet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tablet)
{
    ui->setupUi(this);
    // QGraphicsScene scene;
    // ui->graphicsView->setScene(&scene);
    // QPen pen;
    // pen.setColor(Qt::black);
    // pen.setWidth(2);
    // ui->graphicsView->scene();
    // //    scene
    // //            ->setDefaultPen(pen);

    // // Устанавливаем начальные координаты
    // lastPoint = QPointF();
}

Tablet::~Tablet()
{
    delete ui;
}
