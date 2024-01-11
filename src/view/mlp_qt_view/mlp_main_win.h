#ifndef MLPMAINWIN_H_
#define MLPMAINWIN_H_

#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QStyle>
#include <QTime>
#include <QTimer>
#include <exception>

#include "../../controller/s21_controller_perceptron.h"
#include "s21_tablet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MlpMainWin;
}
QT_END_NAMESPACE

class MlpMainWin : public QMainWindow {
  Q_OBJECT

 public slots:

 public:
  MlpMainWin(QWidget *parent = nullptr);
  ~MlpMainWin();
  void SetControllerObj(s21::ControllerPerceptron *controller_obj) {
    controller_obj_ = controller_obj;
  }

  #pragma pack(push, 1)
  struct BMPHeader {
    char signature[2];
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitDepth;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xResolution;
    int32_t yResolution;
    uint32_t colors;
    uint32_t importantColors;
  };
  #pragma pack(pop)


 private slots:
  void Toggle();

  void on_button1_set_data_clicked();

  void on_button2_load_data_clicked();

  void LoadBmp(std::string file_name);

  void on_button3_add_tests_clicked();

  void on_button4_load_tests_clicked();

  void on_button5_start_edu_clicked();

  void on_button6_graph_clicked();

 private:
  QGraphicsScene *scene_, *scene2_;
  s21::ControllerPerceptron *controller_obj_{};
  Ui::MlpMainWin *ui_{};
  QTimer *m_timer_{};
  QPushButton *button_blink_{};
  QString data_path_1_{};
  QString fileName_{};
  bool set_data_1_{}, load_data_2_{}, add_tests_3_{}, load_tests_4_{},
      load_image_5_{};
  //  QLabel *m_label;
  size_t frame_counter_{};
  QGraphicsPixmapItem *pixmapItem_{}, *pixmapItem2_{};
  //  bool m_isChecked = false;
  QImage personal_image_;
  //  !!!!!!!
  void TabletOpen();
  void Paint();
  void BlinkingButton();
  void BlinkLogic();
  void error_message(QString message);
};
#endif  // MLPMAINWIN_H_
