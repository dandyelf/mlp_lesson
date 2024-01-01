#include <QApplication>
#include <QLocale>

#include "mlp_main_win.h"


int main(int argc, char *argv[]) {
  s21::ControllerPerceptron controller_obj;
  s21::FacadePerceptron facade_model_obj;
  QApplication a(argc, argv);
  MlpMainWin w;
  controller_obj.SetModel(&facade_model_obj);
  w.SetControllerObj(&controller_obj);

  w.show();
  return a.exec();
}
