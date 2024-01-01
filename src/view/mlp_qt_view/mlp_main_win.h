#ifndef MLPMAINWIN_H
#define MLPMAINWIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MlpMainWin; }
QT_END_NAMESPACE

class MlpMainWin : public QMainWindow
{
    Q_OBJECT

public:
    MlpMainWin(QWidget *parent = nullptr);
    ~MlpMainWin();
    void SetControllerObj(s21::Controller &controller_obj);

private:
    Ui::MlpMainWin *ui;
};
#endif // MLPMAINWIN_H
