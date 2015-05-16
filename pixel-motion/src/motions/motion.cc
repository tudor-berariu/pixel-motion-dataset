#include <cmath>

#include <random>

#include "motions/motion.h"

Motion::Motion(int height, int width, int v_stride, int h_stride, int rot, int b_size, double noise)
  : height {height},
    width {width},
    v_stride {v_stride},
    h_stride {h_stride},
    b_size {b_size},
    real_height {(height - b_size) / v_stride},
    real_width {(width - b_size) / h_stride},
    rotation {rot},

    noise {noise}
{ }

Screen Motion::getNextScreen() {
  Screen s(height, vector<Pixel>(width));

  random_device r{ };
  default_random_engine e{r()};
  uniform_real_distribution<float> put_noise(0, 1);

  for(Screen::iterator row_it = s.begin(); row_it < s.end(); ++row_it)
    for(vector<Pixel>::iterator col_it = row_it->begin(); col_it < row_it->end(); ++col_it)
      (*col_it) = (put_noise(e) < noise) ? Pixel::getNoise() : Pixel::getBackground();

  Coord c = move();
  cout << c << " -- scale --> ";
  c.scale(v_stride, h_stride);
  cout << c << " -- rot --> ";
  c.rotate(rotation, height / 2, width / 2);

  cout << c << endl;
  for (int row = c.row; row < (c.row + b_size); row++)
    for (int col = c.col; col < (c.col + b_size); col++)
      if (row >= 0 && row < height && col >= 0 && col < width)
        s[row][col] = Pixel::getRed();

  return s;
}

void Motion::Coord::scale(int v_stride, int h_stride) {
  row *= v_stride;
  col *= h_stride;
}

void Motion::Coord::rotate(int rotation, int c_row, int c_col) {
  row -= c_row;
  col -= c_col;

  float angle = (rotation * M_PI / 180.0);
  float aux_row = row * cos(angle) + col * sin(angle);
  float aux_col = col * cos(angle) - row * sin(angle);

  row = (int)(aux_row + 0.49) + c_row;
  col = (int)(aux_col + 0.49) + c_col;

}

ostream& operator<<(ostream& s, const Motion::Coord& c) {
  s << "(" << c.row << "," << c.col << ")";
  return s;
}
