#include "mlp_main_win.h"
#include "ui_mlp_main_win.h"

MlpMainWin::MlpMainWin(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MlpMainWin) {
  ui_->setupUi(this);
  BlinkingButton();
  scene_ = new QGraphicsScene(this);
  scene2_ = new QGraphicsScene(this);
  ui_->graphicsView->setScene(scene_);
  ui_->graphicsView_2->setScene(scene2_);
}

MlpMainWin::~MlpMainWin() {
  delete ui_;
  delete scene_;
  delete scene2_;
  if (pixmapItem_ != nullptr) delete pixmapItem_;
  if (pixmapItem2_ != nullptr) delete pixmapItem2_;
}

void MlpMainWin::BlinkingButton() {
  m_timer_ = new QTimer(this);
  m_timer_->setInterval(500);
  connect(m_timer_, &QTimer::timeout, this, &MlpMainWin::Toggle);
  m_timer_->start();
  button_blink_ = ui_->button1_set_data;
}

void MlpMainWin::Toggle() {
  // Инвертируем состояние кнопки
  button_blink_->setChecked(!button_blink_->isChecked());
  if (set_data_1_) Paint();
}

void MlpMainWin::BlinkLogic() {
  m_timer_->start();
  button_blink_->setChecked(true);
  if (!set_data_1_)
    button_blink_ = ui_->button1_set_data;
  else if (!load_data_2_)
    button_blink_ = ui_->button2_load_data;
  else if (!add_tests_3_)
    button_blink_ = ui_->button3_add_tests;
  else if (!load_tests_4_)
    button_blink_ = ui_->button4_load_tests;
  else
    button_blink_ = ui_->button5_start_edu;
}

void MlpMainWin::on_button1_set_data_clicked() {
  QString fileName2 = QFileDialog::getOpenFileName(
      this, tr("Open Csv File"), data_path_1_, tr("CSV Files (*.csv)"));
  if (fileName2 != "") {
    data_path_1_ = fileName2;
    try {
      controller_obj_->OpenCsv(data_path_1_.toStdString(), 784);
    } catch (std::exception& e) {
      error_message(e.what());
      return;
    }
  } else {
    error_message("Нет файла");
  }
  set_data_1_ = true;
  load_image_5_ = false;
  BlinkLogic();
  ui_->textBrowser->setText(
  QString::number(controller_obj_->GetCsv()->size()));
  Paint();
}

void MlpMainWin::on_button2_load_data_clicked() {
  QString fileName2 = QFileDialog::getOpenFileName(
    this, tr("Open Bmp File"), data_path_1_, tr("Bmp Files (*.bmp)"));
  if (fileName2 != "") {
    data_path_1_ = fileName2;
    LoadBmp(fileName2.toStdString());
  }
  load_data_2_ = true;
  BlinkLogic();
}

void MlpMainWin::LoadBmp(std::string file_name) {
   QImage image(file_name.c_str());

    // Проверка, удалось ли загрузить файл
    if (image.isNull()) {
        qDebug() << "Не удалось загрузить файл BMP";
        error_message("load bmp");
        return;
    }
    // Преобразование QImage в QPixmap, если необходимо
    if (pixmapItem2_ == nullptr) delete pixmapItem2_;
  // Создаем QImage
    QImage scale_image = image.scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scale_image = scale_image.scaled(280, 280, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  // Создаем QGraphicsPixmapItem и устанавливаем изображение
    pixmapItem2_ = new QGraphicsPixmapItem(QPixmap::fromImage(scale_image));
  // Добавляем QGraphicsPixmapItem на сцену
    scene2_->clear();
    scene2_->addItem(pixmapItem2_);
    load_image_5_ = true;
}

void MlpMainWin::on_button3_add_tests_clicked() {
  add_tests_3_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button4_load_tests_clicked() {
  load_tests_4_ = true;
  BlinkLogic();
}

void MlpMainWin::on_button5_start_edu_clicked() {
  set_data_1_ = false;
  load_data_2_ = false;
  add_tests_3_ = false;
  load_tests_4_ = false;
  BlinkLogic();
}

void MlpMainWin::Paint() {
  // Создаем вектор пикселей
  const std::vector<unsigned char> pixelVector =
      controller_obj_->GetCsv()->at(frame_counter_);
  scene_->clear();
  if (pixmapItem_ == nullptr) delete pixmapItem_;
  // Создаем QImage
  QImage image(pixelVector.data() + pixel, 28, 28, QImage::Format_Grayscale8);
  image = image.scaled(280, 280, Qt::KeepAspectRatio);
  // Создаем QGraphicsPixmapItem и устанавливаем изображение
  pixmapItem_ = new QGraphicsPixmapItem(QPixmap::fromImage(image));
  // Добавляем QGraphicsPixmapItem на сцену
  scene_->addItem(pixmapItem_);
  if (frame_counter_ < controller_obj_->GetCsv()->size()) frame_counter_++;
}

void MlpMainWin::error_message(QString message) {
  QMessageBox messageBox;
  messageBox.setFixedSize(500, 200);
  messageBox.information(0, "Info", message);
}

void MlpMainWin::on_button6_graph_clicked() {
  TabletOpen();
  load_image_5_ = true;
  scene2_->clear();
  if (pixmapItem2_ == nullptr) delete pixmapItem2_;
  // Создаем QImage
  // Создаем QGraphicsPixmapItem и устанавливаем изображение
  QImage image = personal_image_.scaled(280, 280, Qt::KeepAspectRatio);
  pixmapItem2_ = new QGraphicsPixmapItem(QPixmap::fromImage(image));
  // Добавляем QGraphicsPixmapItem на сцену
  scene2_->addItem(pixmapItem2_);
}

void MlpMainWin::TabletOpen() {
  Tablet tablet_okno(this, &personal_image_);
  tablet_okno.setModal(true);
  tablet_okno.exec();
}
