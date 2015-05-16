#ifndef MOTION_H
#define MOTION_H

#include <vector>
#include <iostream>
#include "pixel/pixel.h"

using namespace std;

class Motion {
 public:
  struct Coord {
    int row;
    int col;
    void scale(int, int);
    void rotate(int, int, int);

    friend ostream& operator<<(ostream&, const Motion::Coord&);
  };

  Motion(int, int, int, int, int, int, double);

  Screen getNextScreen();
  virtual Coord move()=0;

 private:

  int height;
  int width;

  int v_stride;
  int h_stride;

  int b_size;

 protected:
  int real_height;
  int real_width;

 private:
  int rotation;
  double noise;
};

#endif
