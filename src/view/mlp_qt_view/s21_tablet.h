#ifndef S21_TABLET_H
#define S21_TABLET_H

#include <QDialog>

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

#endif // S21_TABLET_H
