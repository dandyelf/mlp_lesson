#ifndef S21_FACADE_PERCEPTRONE_
#define S21_FACADE_PERCEPTRONE_

#include <string>

#include "./s21_model_perceptron.h"

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

  void OpenCsv(std::string file_name) { csv_vector_ = ParseCsv(file_name); }
  const std::vector<std::vector<int>>* GetCsv() {
    const std::vector<std::vector<int>>* tmp = &csv_vector_;
    return tmp;
  }

 private:
  std::vector<std::vector<int>> csv_vector_;
};
}  // namespace s21

#endif  // S21_FACADE_PERCEPTRONE_