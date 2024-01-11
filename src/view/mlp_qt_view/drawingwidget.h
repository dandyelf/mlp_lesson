#ifndef DRAWINGWIDGET_H_
#define DRAWINGWIDGET_H_

#include <QtWidgets>
#include <QGraphicsBlurEffect>

class DrawingWidget : public QWidget {
 public:
  DrawingWidget(QWidget *parent = nullptr) : QWidget(parent) {
    parent_ = parent;
    setFixedSize(280, 280);  // Устанавливаем размер виджета 280 x 280 пикселей
    drawing = false;
    // Создаем изображение размером 28 x 28 пикселей
    image = QImage(280, 280, QImage::Format_Grayscale8);
    image.fill(Qt::white);
  }

  void Reset() {
    image.fill(Qt::white);
    update();
  }

  QImage GetImage() { 
    QImage scaledImage = image.scaled(this->size(), Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    scaledImage = scaledImage.scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scaledImage = scaledImage.scaled(this->size(), Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    return scaledImage; 
  }

 protected:
  void mousePressEvent(QMouseEvent *event) override {
    if (event->button() == Qt::LeftButton) {
      lastPoint = event->pos();
      drawing = true;
    }
  }

  void mouseMoveEvent(QMouseEvent *event) override {
    if (event->buttons() & Qt::LeftButton && drawing) {
      QPainter painter(&image);        
      QPen pen(Qt::black, 35, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
      painter.setPen(pen);
      painter.setRenderHint(QPainter::Antialiasing, true);
      painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
      painter.drawLine(
          lastPoint,
          event->pos());
      lastPoint = event->pos();
      update();  // Перерисовываем виджет
    }
  }

  void mouseReleaseEvent(QMouseEvent *event) override {
    if (event->button() == Qt::LeftButton && drawing) {
      drawing = false;
    }
  }

  void paintEvent(QPaintEvent *event) override {
    if (event == nullptr) return;
    QPainter painter(this);
    // Масштабируем изображение до размеров виджета
    QImage scaledImage = image.scaled(this->size(), Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    scaledImage = scaledImage.scaled(28, 28, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scaledImage = scaledImage.scaled(this->size(), Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    painter.drawImage(QPoint(0, 0), scaledImage);
  }

 private:
  QWidget *parent_;
  bool drawing;
  QPoint lastPoint;
  QImage image;
};

#endif  // DRAWINGWIDGET_H_
