#ifndef SPIRAL_H
#define SPIRAL_H

#include <vector>
#include <random>

#include "pixel/pixel.h"
#include "motions/motion.h"

using namespace std;

class Spiral : public Motion {

public:
  enum class Direction {Clock = -1, Trig = 1};
  enum class Orientation {In = -1, Out = 1};

  Spiral(int, int, int, int, int, Direction, Orientation);
  Spiral(int, int, int, int, int, Direction, Orientation, double);
  Spiral(int, int, int, int, int, Direction, Orientation, int);
  Spiral(int, int, int, int, int, Direction, Orientation, int, double);

  Coord move();
  void reset();

  int print() const;

private:
  Direction direction;
  Orientation orientation;

  Coord center;

  double radius;
  double angle;
};
#endif
