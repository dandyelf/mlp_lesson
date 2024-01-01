#include "../controller/s21_controller_perceptron.h"
#include "gtest/gtest.h"

TEST(ControllerPereceptron, SetModel) {
  s21::ControllerPerceptron controller_perceptron;
  s21::FacadePerceptron facade_perceptron;
  controller_perceptron.SetModel(&facade_perceptron);
  EXPECT_EQ(432, 432);
}
