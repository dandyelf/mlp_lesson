#include "../model/s21_facade_perceptron.h"
#include "gtest/gtest.h"

std::string file_name = TESTS_OBJ_PATH;

TEST(ModelPerceptron, StdConstruct) {
  s21::FacadePerceptron facade_perceptron;
  int set = 0;
  if (facade_perceptron.IsAllGood()) set = 432;
  EXPECT_EQ(set, 432);
}

TEST(ModelPerceptron, TtrainSet) {
  s21::FacadePerceptron facade_perceptron;
  // facade_perceptron.OpenCsv(file_name + "my.csv");
  facade_perceptron.OpenCsv(file_name + "emnist-letters-test.csv", 784);
  // facade_perceptron.OpenCsv(file_name + "emnist-letters-train.csv");

  auto tmp = facade_perceptron.GetCsv();
  // for (size_t i = 0; i < tmp->size(); i++) {
  //   auto set = tmp->at(i);
  //   std::cout << (set.size() - 1) << std::endl;
  // }

  EXPECT_EQ(tmp->size(), 14800);
}