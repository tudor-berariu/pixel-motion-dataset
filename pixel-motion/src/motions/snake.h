#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <random>

#include "pixel/pixel.h"

using namespace std;

class Snake {
public:
  enum class HDirection {LR, RL};
  enum class VDirection {Up, Down};

  Snake(int, int, HDirection, VDirection);
  Snake(int, int, HDirection, VDirection, double);

  Screen getNextScree();

private:
  int height;
  int width;
  HDirection h_direction;
  VDirection v_direction;
  double noise; 

  random_device r;
  default_random_engine e;

  uniform_int_distribution<int> next_row;
  uniform_int_distribution<int> next_col;

  int row;
  int col;
};
#endif
