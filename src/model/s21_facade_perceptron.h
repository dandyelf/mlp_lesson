#ifndef S21_FACADE_PERCEPTRONE_
#define S21_FACADE_PERCEPTRONE_

#include "../model/s21_facade_perceptron.h"

namespace s21 {
class FacadePerceptron {
  public:
  FacadePerceptron() = default;
  FacadePerceptron(const FacadePerceptron&) = delete;
  FacadePerceptron(FacadePerceptron&&) = delete;
  ~FacadePerceptron() = default;
  FacadePerceptron& operator=(const FacadePerceptron&) = delete;
  FacadePerceptron& operator=(FacadePerceptron&&) = delete;
  bool IsAllGood() { return true; }
};
}  // namespace s21

#endif  // S21_FACADE_PERCEPTRONE_