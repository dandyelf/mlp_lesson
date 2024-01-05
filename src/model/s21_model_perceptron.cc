#include "s21_model_perceptron.h"

std::vector<std::vector<int>> ParseCsv(const std::string& filename) {
  std::vector<std::vector<int>> data;
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    return data;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string token;
    std::vector<int> image;
    // Чтение метки
    std::getline(iss, token, ',');
    image.push_back(std::stoi(token));
    if (image[lable] < 0) {
      throw std::runtime_error("lable token");
    }
    // Чтение пикселей
    while (std::getline(iss, token, ',')) {
      image.push_back(std::stoi(token));
      if (255 < image.back() || image.back() < 0) {
        throw std::runtime_error("pixel token");
      }
    }
    data.push_back(image);
  }
  return data;
}
