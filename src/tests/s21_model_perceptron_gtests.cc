#include "gtest/gtest.h"
#include "../model/s21_facade_perceptron.h"

TEST(ModelPerceptron, StdConstruct) {
  s21::FacadePerceptron facade_perceptron;
  int set = 0;
  if(facade_perceptron.IsAllGood()) set = 432;
  EXPECT_EQ(set, 432);
}