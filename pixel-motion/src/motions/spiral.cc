#include "motions/spiral.h"

Spiral::Spiral(int height, int width, int v_stride, int h_stride, int rotation,
               Direction direction, Orientation orientation)
  : Spiral(height, width, v_stride, h_stride, rotation, direction, orientation, 3, 0.05) { }

Spiral::Spiral(int height, int width, int v_stride, int h_stride, int rotation,
               Direction direction, Orientation orientation,
               int b_size)
  : Spiral(height, width, v_stride, h_stride, rotation, direction, orientation, b_size, 0.05) { }

Spiral::Spiral(int height, int width, int v_stride, int h_stride, int rotation,
               Direction direction, Orientation orientation,
               double noise)
  : Spiral(height, width, v_stride, h_stride, rotation, direction, orientation, 3, noise) { }


Spiral::Spiral(int height, int width, int v_stride, int h_stride, int rotation,
               Direction direction, Orientation orientation,
               int b_size, double noise)
  : Motion {height, width, v_stride, h_stride, rotation, b_size, noise},
    direction {direction},
    orientation {orientation},
    angle {0.0}
 {
   reset();
 }

Spiral::Coord Spiral::move() {
  angle += ((double)direction * (45.0 / radius));
  if (angle > 360.0) angle -= 360.0;
 
  radius += (double)orientation * 0.075;
  int new_row = center.row - radius * sin(angle * M_PI / 180.0);
  int new_col = center.col + radius * cos(angle * M_PI / 180.0);
  if (new_row == center.row && new_col == center.col) {
    reset();
  }
  if (radius > real_height/2 && radius > real_width/2) {
    reset();
  }
  return Coord{new_row, new_col};
}

void Spiral::reset() {
  random_device r{ };
  default_random_engine e{r()};

  uniform_int_distribution<int> next_row(0, real_height/3);
  uniform_int_distribution<int> next_col(0, real_width/3);
  
  center = Coord{real_height/3 + next_row(e), real_width/3 + next_col(e)};

  if (orientation == Orientation::Out) {
    radius = 1.0;
  }
  else {
    float max_radius = numeric_limits<float>::max();
    max_radius = (real_height > real_width) ? real_height : real_width;
    /*
      if ((float)center.row < max_radius) max_radius = center.row;
      if ((float)(real_height - center.row) < max_radius) max_radius = real_height - center.row;
      if ((float)center.col < max_radius) max_radius = center.col;
      if ((float)(real_width - center.col) < max_radius) max_radius = real_width - center.col;
    */
    uniform_real_distribution<float> next_radius(0, max_radius/2);
    radius = next_radius(e);
  }
}
