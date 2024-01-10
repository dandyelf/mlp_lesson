#ifndef S21_TABLET_H_
#define S21_TABLET_H_

#include <QDialog>
#include "drawingwidget.h"

namespace Ui {
class Tablet;
}

class Tablet : public QDialog
{
    Q_OBJECT

public:
    explicit Tablet(QWidget *parent = nullptr);
    ~Tablet();

private:
    QPointF lastPoint;
    bool painting;
    QTimer *timer;
    Ui::Tablet *ui;
};

#endif // S21_TABLET_H_
