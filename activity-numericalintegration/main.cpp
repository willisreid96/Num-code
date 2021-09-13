#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  int main (int argc, char* argv[]) {

    if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }

  float x = 0.0;
  int id = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  int n = atoi(argv[4]);
  int i = atoi(argv[5]);
  float intergral = 0.0;
  float func = (b-a)/n;
    auto start = std::chrono::steady_clock::now();
  for(int c=0; c<n; c++) {
    switch (id) {
    case 1:
      intergral += f1(a+(c+.5)*func, i) * func;
      break;
    case 2:
      intergral += f2(a+(c+.5)*func, i) * func;
      break;
    case 3:
      intergral += f3(a+(c+.5)*func, i) * func;
      break;
    case 4:
      intergral += f4(a+(c+.5)*func, i) * func;
      break;
    default:
      break;
    }
  }
  
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> t = end-start;
  std::cout << intergral << "\n";
  std::cerr << t.count() <<" seconds\n";

  
  return 0;
}
