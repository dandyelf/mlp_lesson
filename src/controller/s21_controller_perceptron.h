#ifndef S21_CONTROLLER_PERCEPTRONE_
#define S21_CONTROLLER_PERCEPTRONE_

#include "../model/s21_facade_perceptron.h"

namespace s21 {
class ControllerPerceptron {
 public:
  ControllerPerceptron() = default;
  ControllerPerceptron(const ControllerPerceptron&) = delete;
  ControllerPerceptron(ControllerPerceptron&&) = delete;
  ~ControllerPerceptron() = default;
  ControllerPerceptron& operator=(const ControllerPerceptron&) = delete;
  ControllerPerceptron& operator=(ControllerPerceptron&&) = delete;
  void SetModel(s21::FacadePerceptron* facade) { facade_ = facade; }

 private:
  s21::FacadePerceptron* facade_;
};
}  // namespace s21

#endif  // S21_CONTROLLER_PERCEPTRONE_