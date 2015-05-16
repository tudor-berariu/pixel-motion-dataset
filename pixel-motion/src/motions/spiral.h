#ifndef SPIRAL_H
#define SPIRAL_H

#include <vector>
#include <random>

#include "pixel/pixel.h"

using namespace std;

class Spiral {

public:
  enum class Direction {Trig, Clock};
  enum class Orientation {In, Out};

  Spiral(int, int, Direction, Orientation);
  Spiral(int, int, Direction, Orientation, double);

  Screen getNextScreen();

private:
  int height;
  int width;
  Direction direction;
  Orientation orientation;
  double noise;

  random_device r;
  default_random_engine e;

  uniform_int_distribution<int> next_row;
  uniform_int_distribution<int> next_col;

  int row;
  int col;
};
#endif
