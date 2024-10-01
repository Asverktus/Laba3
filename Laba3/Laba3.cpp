#include <iostream>
#include <iomanip>  
#include <cmath>    

// Функция для расчета относительного количества жидкости
double calculatePhi(double y_g, double y_l, double u_g, double u_l) {
  double G = y_g / y_l;
  double M = u_l / u_g;
  double K = G * M;

  double Phi;
  if (K < 0.5) {
    Phi = 0.8 / (1 + 2.03 * pow(G, 0.26) * pow(M, 0.05));
  }
  else {
    Phi = 0.8 / (1 + 2.15 * pow(G, 0.16) * pow(M, 0.03));
  }

  return Phi;
}

int main() {

  setlocale(LC_ALL, "rus");

  // Заданные параметры для воздуха
  double y_g = 0.0011;  // Удельный вес газа, г/см^3
  double u_g = 0.00018; // Динамическая вязкость газа, г/см·с

  // Данные для различных жидкостей
  struct Liquid {
    std::string name;
    double y_l;  // Удельный вес жидкости, г/см^3
    double u_l;  // Динамическая вязкость жидкости, г/см·с
  };

  Liquid liquids[] = {
      {"Спирт", 0.79, 0.012},
      {"Анилин", 1.03, 0.04},
      {"Глицерин", 1.26, 13.5}
  };

  // Вывод результатов
  std::cout << std::fixed << std::setprecision(3);
  std::cout << std::left << std::setw(10) << "Жидкость" << std::setw(10) << "Phi" << std::setw(10) << "K" << std::endl;
  std::cout << "---------------------------------" << std::endl;

  for (const auto& liquid : liquids) {
    double Phi = calculatePhi(y_g, liquid.y_l, u_g, liquid.u_l);
    double G = y_g / liquid.y_l;
    double M = liquid.u_l / u_g;
    double K = G * M;

    std::cout << std::left << std::setw(10) << liquid.name << std::setw(10) << Phi << std::setw(10) << K << std::endl;
  }

  return 0;
}