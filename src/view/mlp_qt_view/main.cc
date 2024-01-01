#include "mlp_main_win.h"

#include <QApplication>
#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    s21::Controller controller_obj;
    s21::Facade facade_model_obj;
    QApplication a(argc, argv);
    MlpMainWin w;
    controller_obj.SetModel(&facade_model_obj);
    w.SetControllerObj(&controller_obj);


    w.show();
    return a.exec();
}
